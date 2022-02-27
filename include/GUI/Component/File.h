#pragma once

#include <cstdint>
#include <list>

#include <QMainWindow>
#include <QString>

namespace tas::dtm
{
    class File
    {
    private:
        QString fileName = "";
        QMainWindow *parent;
        std::list<uint8_t> *fileByteList;

    public:
        File(QMainWindow *parent);
        ~File();
        std::list<uint8_t> *open();
        void save(std::list<uint8_t> *data);
    };
}
