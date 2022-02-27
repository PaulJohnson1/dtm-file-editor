#pragma once

#include <cstddef>
#include <cstdint>

namespace tas::dtm::util
{
    template <typename T>
    constexpr T readMemoryOffsetAs(uint8_t *bytes, size_t offset)
    {
        T value = 0;

        for (size_t i = 0; i < sizeof(T); i++)
        {
            value |= (T)bytes[offset + i] << (i << 3);
        }

        return value;
    }
}
