#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include <DTM/BinaryFormat/DataFrame.h>
#include <DTM/BinaryFormat/Header.h>
#include <DTM/Reader.h>
#include <Util/File.h>

namespace tas::dtm
{
    /**
     * Contains the decoded DTM file's data (frames, headers)
     */
    class DecodedDTMFile
    {
    private:
        File *file;
    public:
        binary::Reader reader;

        DecodedDTMFile(File *bytes);
        ~DecodedDTMFile();
    };
}
