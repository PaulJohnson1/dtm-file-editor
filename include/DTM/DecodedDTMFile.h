#pragma once

#include <DTM/Reader.h>
#include <Util/File.h>

namespace tas::dtm
{
    /**
     * Contains the decoded DTM file's data (frames, headers)
     */
    class DecodedDTMFile
    {
    public:
        File *file;
        binary::Reader reader;

        DecodedDTMFile(File *bytes);
        ~DecodedDTMFile();
    };
}
