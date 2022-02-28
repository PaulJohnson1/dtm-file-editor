#include <Util/File.h>

#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <cstdint>

#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>

#include <DTM/Reader.h>

namespace tas::dtm
{
    File::File(uint8_t *bytes, size_t size) : bytes(bytes), size(size)
    {
    }

    File::~File()
    {
        delete[] bytes;
    }

    File *File::open(QMainWindow *parent)
    {
        QString qFileName = QFileDialog::getOpenFileName(parent,
                                                         "Open DTM File",
                                                         "",
                                                         "Dolphin Tas Movie (*.dtm)");

        if (qFileName == "")
            throw std::runtime_error("Couldn't open file");

        QFile qFile(qFileName);
        if (!qFile.exists())
            throw std::runtime_error("Couldn't open file");

        std::string filePath = qFileName.toStdString();
        std::fstream stream(filePath);

        stream.seekg(0, std::ios::end);
        size_t fileSize = stream.tellg();
        stream.seekg(0, std::ios::beg);

        // potentially will be over 8 mb which would overflow the stack
        uint8_t *fileContents = new uint8_t[fileSize];

        stream.read((char *)fileContents, fileSize);

        File *file = new File(fileContents, fileSize);

        return file;
    }

    void File::save(File *data)
    {
    }
}
