#pragma once

#include <cstdint>

#include <QMainWindow>
#include <QString>

#include <DTM/Reader.h>

namespace tas::dtm
{
    class File
    {
    private:
        QString fileName = "";
        QMainWindow *parent;
        dtm::binary::Reader *frames;

    public:
        File(QMainWindow *parent);
        ~File();
        dtm::binary::Reader *open();
        void save(dtm::binary::Reader *data);
    };
}
