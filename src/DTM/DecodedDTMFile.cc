#include <DTM/DecodedDTMFile.h>

#include <cstddef>
#include <cstdint>
#include <vector>

#include <DTM/BinaryFormat/Header.h>
#include <DTM/BinaryFormat/DataFrame.h>
#include <DTM/Reader.h>
#include <Util/File.h>

namespace tas::dtm
{
    DecodedDTMFile::DecodedDTMFile(File *file) : file(file), reader(binary::Reader(file->bytes, file->size))
    {
    }
}
