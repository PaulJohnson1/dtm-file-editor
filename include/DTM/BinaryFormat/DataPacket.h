#pragma once

#include <cstdint>

namespace tas::dtm::binary
{
    enum class DataReportOpCode
    {

    }

    struct DataPacket
    {
        uint8_t dataByteSize;
        uint8_t inputFlags;

    };
}
