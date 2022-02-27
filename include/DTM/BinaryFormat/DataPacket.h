#pragma once

#include <cstdint>

#include <DTM/BinaryFormat/Constants/DataReportMode.h>

namespace tas::dtm::binary
{
    class DataPacket
    {
    public:
        uint8_t dataByteSize;
        uint8_t reportMode;
        uint16_t buttonFlags;
        uint8_t accelerometor[3];
        
        // for ir and extension data we use the max size possible for the packet
        uint8_t irData[16];
        uint8_t extensionData[19];
    };
}
