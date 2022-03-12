#pragma once

#include <bitset>
#include <cstdint>

namespace tas::dtm::binary
{
    class DataFrame
    {
    public:
        uint64_t inputIndex;
        uint8_t dataByteSize;
        uint8_t reportMode;
        std::bitset<16> buttonFlags;
        uint8_t accelerometor[3];
        
        // for ir and extension data we use the max size possible for the frame
        uint8_t irData[16];
        uint8_t extensionData[19];
    };
}
