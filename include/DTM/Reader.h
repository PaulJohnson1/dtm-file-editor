#pragma once

#include <cstddef>
#include <vector>

#include <DTM/BinaryFormat/DataPacket.h>
#include <DTM/BinaryFormat/Header.h>

namespace tas::dtm::binary
{
    /**
     * Writes to a `DecodedDTMFile`
     */
    class Reader
    {
    private:
        uint8_t *bytes;
        size_t size;

        /**
         * @brief parses the frame at the position
         * 
         * @param currentPosition aka offset
         * @return returns true if you are at the end of the binary
         */
        bool parsePacket(size_t &currentPosition);

    public:
        Header dtmHeader;
        std::vector<DataPacket> packets;

        Reader(uint8_t *bytes, size_t size);
        ~Reader();
    };
}
