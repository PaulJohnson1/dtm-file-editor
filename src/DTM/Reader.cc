#include <DTM/Reader.h>

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <exception>

#include <DTM/BinaryFormat/Constants/DataReportMode.h>
#include <DTM/BinaryFormat/DataFrame.h>
#include <DTM/BinaryFormat/Header.h>
#include <DTM/DecodedDTMFile.h>
#include <Util/ReadMemoryOffsetAs.h>

namespace tas::dtm::binary
{
    Reader::Reader(uint8_t *bytes, size_t size) : bytes(bytes), size(size)
    {
        if (size < 0x100)
            throw std::runtime_error("buffer is smaller than 256 bytes");

        dtmHeader = bytes;

        size_t position = 0x100;
        uint64_t polls = 0;

        while (true)
        {
            polls++;
            if (parseFrame(position, polls))
                break;
        }
    }

    bool Reader::parseFrame(size_t &currentPosition, uint64_t polls)
    {
        using namespace constants;
        using util::readMemoryOffsetAs;

        size_t frameSize = bytes[currentPosition];
        size_t frameEnd = currentPosition + frameSize + 1;

        if (currentPosition + frameSize + 1 == size)
            return true;

        DataFrame frame;
        frame.inputIndex = polls;

        uint8_t offset = 0;

        if (readMemoryOffsetAs<uint8_t>(bytes, currentPosition + 1) == 0xa1)
            offset = 1;

        frame.reportMode = readMemoryOffsetAs<uint8_t>(bytes, currentPosition + offset + 1);

        if (frame.reportMode == DataReportMode::Buttons)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
        }
        else if (frame.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 10, frame.irData);
            std::copy(bytes + offset + 11, bytes + offset + 20, frame.extensionData);
        }
        else if (frame.reportMode == DataReportMode::Buttons_Accelerometer)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 6, frame.accelerometor);
        }
        else if (frame.reportMode == DataReportMode::Buttons_Accelerometer_ExtensionBytes16)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 6, frame.accelerometor);
            std::copy(bytes + offset + 7, bytes + offset + 16, frame.extensionData);
        }
        else if (frame.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes10_ExtensionBytes6)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 6, frame.accelerometor);
            std::copy(bytes + offset + 7, bytes + offset + 10, frame.accelerometor);
            std::copy(bytes + offset + 11, bytes + offset + 17, frame.accelerometor);
        }
        else if (frame.reportMode == DataReportMode::Buttons_Accelerometer_IrBytes12)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 6, frame.accelerometor);
            std::copy(bytes + offset + 7, bytes + offset + 19, frame.irData);
        }
        else if (frame.reportMode == DataReportMode::Buttons_IrBytes10_ExtensionBytes9)
        {
            frame.buttonFlags = readMemoryOffsetAs<uint16_t>(bytes, currentPosition + offset + 2);
            std::copy(bytes + offset + 3, bytes + offset + 10, frame.accelerometor);
            std::copy(bytes + offset + 11, bytes + offset + 20, frame.accelerometor);
        }
        else if (frame.reportMode == DataReportMode::ExtensionBytes21)
        {
            std::copy(bytes + 2, bytes + 23, frame.extensionData);
        }
        else
            throw std::runtime_error(std::string("unknown report mode ") + std::to_string(frame.reportMode));

        currentPosition += frameSize + 1;

        frames.push_back(frame);

        return false;
    }

    Reader::~Reader()
    {
    }
}
