#pragma once

#include <cstddef>
#include <cstdint>

#include <QWidget>
#include <QString>

#include <DTM/Reader.h>

namespace tas::dtm
{
    class File
    {
    public:
        uint8_t *bytes;
        size_t size;

        File(uint8_t *bytes, size_t size);
        ~File();

        static File *open(QWidget *parent);
        static void save(File *data);
    };
}