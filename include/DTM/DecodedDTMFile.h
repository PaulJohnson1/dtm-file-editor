#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include <DTM/BinaryFormat/DataPacket.h>
#include <DTM/BinaryFormat/Header.h>
#include <DTM/Reader.h>

namespace tas::dtm
{
    /**
     * Contains the decoded DTM file's data (frames, headers)
     */
    class DecodedDTMFile
    {
    private:
        binary::Reader reader;
    public:
        binary::Header dtmHeader;
        std::vector<binary::DataPacket> packets;

        DecodedDTMFile(uint8_t *bytes, size_t size);
    };
}
