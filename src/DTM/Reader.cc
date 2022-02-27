#include <DTM/Reader.h>

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <exception>

#include <DTM/BinaryFormat/Constants/DataReportMode.h>
#include <DTM/BinaryFormat/DataPacket.h>
#include <DTM/BinaryFormat/Header.h>
#include <Util/ReadMemoryOffsetAs.h>

namespace tas::dtm::binary
{
    Reader::Reader(uint8_t *bytes, size_t size) : bytes(bytes), size(size)
    {
        if (size < 0x100)
            throw std::runtime_error("buffer is smaller than 256 bytes");

        header = bytes;

        size_t position = 0x100;

        while (true)
        {
            if (parsePacket(position))
                break;
        }
    }

    bool Reader::parsePacket(size_t &currentPosition)
    {
        using namespace constants;
        using util::readMemoryOffsetAs;

        size_t packetSize = bytes[currentPosition];
        size_t packetEnd = currentPosition + packetSize + 1;

        if (currentPosition + packetSize + 1 == size)
            return true;

        DataPacket packet;

        packet.reportMode = readMemoryOffsetAs<uint8_t>(bytes, currentPosition + 1);

        if (packet.reportMode == DataReportMode::Buttons)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
        }
        else if (packet.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 10, packet.irData);
            std::copy(bytes + 11, bytes + 20, packet.extensionData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_ExtensionBytes16)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 16, packet.extensionData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes10_ExtensionBytes6)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 10, packet.accelerometor);
            std::copy(bytes + 11, bytes + 17, packet.accelerometor);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes12)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 19, packet.irData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            packet.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + 2);
            std::copy(bytes + 3, bytes + 10, packet.accelerometor);
            std::copy(bytes + 11, bytes + 20, packet.accelerometor);
        }
        else if (packet.reportMode == DataReportMode::ExtensionBytes21)
        {
            std::copy(bytes + 2, bytes + 23, packet.extensionData);
        }
        else
            throw std::runtime_error("unknown report mode");

        currentPosition += packetSize + 1;

        return false;
    }

    Reader::~Reader()
    {
    }
}
