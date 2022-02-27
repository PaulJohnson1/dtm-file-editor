#include <DTM/BinaryFormat/File.h>

#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>

#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>

#include <DTM/Reader.h>

namespace tas::dtm
{
    File::File(QMainWindow *parent)
    {
        this->parent = parent;
    }

    File::~File()
    {
    }

    dtm::binary::Reader *File::open()
    {
        QString qFileName = QFileDialog::getOpenFileName(parent,
                                                         "Open DTM File",
                                                         this->fileName,
                                                         "Dolphin Tas Movie (*.dtm)");

        if (qFileName == "")
            throw std::runtime_error("Couldn't open file");

        QFile qFile(qFileName);
        if (!qFile.exists())
            throw std::runtime_error("Couldn't open file");

        std::string filePath = qFileName.toStdString();
        std::fstream file(filePath);

        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        uint8_t *fileContents = new uint8_t[fileSize];

        file.read((char *)fileContents, fileSize);

        dtm::binary::Reader *reader = new dtm::binary::Reader(fileContents, fileSize);

        return reader;
    }

    void File::save(dtm::binary::Reader *data)
    {
    }
}
