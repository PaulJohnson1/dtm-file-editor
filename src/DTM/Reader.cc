#include <DTM/Reader.h>

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <exception>

#include <iostream> // dont forget to remove pls

#include <DTM/BinaryFormat/DataPacket.h>
#include <DTM/BinaryFormat/Constants/DataReportMode.h>

namespace tas::dtm::binary
{
    Reader::Reader(uint8_t *bytes, size_t size) : bytes(bytes), size(size)
    {
        if (size < 0x100)
            throw std::runtime_error("buffer is smaller than 256 bytes");

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

        size_t packetSize = bytes[currentPosition];
        size_t packetEnd = currentPosition + packetSize + 1;

        // this gets ugly
        auto fromLocalAddressU8 = [this, currentPosition](size_t local) -> uint8_t
        {
            return (uint8_t)bytes[currentPosition + local];
        };
        auto fromLocalAddressU16 = [this, currentPosition](size_t local) -> uint16_t
        {
            uint8_t a = bytes[currentPosition + local];
            uint8_t b = bytes[currentPosition + local + 1];

            return (uint16_t)((uint16_t)(a) | (uint16_t)(b << 8));
        };
        auto fromLocalAddressU32 = [this, currentPosition](size_t local) -> uint32_t
        {
            uint8_t a = bytes[currentPosition + local];
            uint8_t b = bytes[currentPosition + local + 1];
            uint8_t c = bytes[currentPosition + local + 2];
            uint8_t d = bytes[currentPosition + local + 3];

            return (uint32_t)((uint32_t)(a) | (uint32_t)(b << 8) | (uint32_t)(b << 16) | (uint32_t)(b << 24));
        };
        auto fromLocalAddressI32 = [this, currentPosition](size_t local) -> int32_t
        {
            uint8_t a = bytes[currentPosition + local];
            uint8_t b = bytes[currentPosition + local + 1];
            uint8_t c = bytes[currentPosition + local + 2];
            uint8_t d = bytes[currentPosition + local + 3];

            return (int32_t)((int32_t)(a) | (int32_t)(b << 8) | (int32_t)(b << 16) | (int32_t)(b << 24));
        };

        if (currentPosition + packetSize + 1 == size)
            return true;

        DataPacket packet;

        packet.reportMode = fromLocalAddressU8(1);

        if (packet.reportMode == DataReportMode::Buttons)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::cout << packet.buttonFlags << std::endl;
        }
        else if (packet.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::copy(bytes + 3, bytes + 10, packet.irData);
            std::copy(bytes + 11, bytes + 20, packet.extensionData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_ExtensionBytes16)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 16, packet.extensionData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes10_ExtensionBytes6)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 10, packet.accelerometor);
            std::copy(bytes + 11, bytes + 17, packet.accelerometor);
        }
        else if (packet.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes12)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
            std::copy(bytes + 3, bytes + 6, packet.accelerometor);
            std::copy(bytes + 7, bytes + 19, packet.irData);
        }
        else if (packet.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            packet.buttonFlags = fromLocalAddressU16(2);
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
