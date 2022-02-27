#pragma once

#include <cstddef>
#include <cstdint>

namespace tas::dtm::binary
{
    class Writer
    {
    public:
        Writer(uint8_t *bytes, size_t size);
        ~Writer();
    };
}
