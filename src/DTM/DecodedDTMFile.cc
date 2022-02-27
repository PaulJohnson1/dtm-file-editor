#include <DTM/DecodedDTMFile.h>

#include <cstddef>
#include <cstdint>
#include <vector>

#include <DTM/BinaryFormat/Header.h>
#include <DTM/BinaryFormat/DataFrame.h>
#include <DTM/Reader.h>

namespace tas::dtm
{
    DecodedDTMFile::DecodedDTMFile(uint8_t *bytes, size_t size) : reader(binary::Reader(bytes, size))
    {
    }
}
