#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include <DTM/BinaryFormat/DataFrame.h>
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
        bool parseFrame(size_t &currentPosition, uint64_t polls);

    public:
        Header dtmHeader;
        std::vector<DataFrame> frames;

        Reader(uint8_t *bytes, size_t size);
        ~Reader();
    };
}
