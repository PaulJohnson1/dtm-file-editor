#include <GUI/Component/File.h>

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

namespace tas::dtm
{
    File::File(QMainWindow *parent)
    {
        this->parent = parent;
    }

    File::~File()
    {
    }

    std::list<uint8_t> *File::open()
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

        std::list<uint8_t> *list = new std::list<uint8_t>();
        for (size_t i = 0; i < fileSize; i++)
        {
            list->push_back(fileContents[i]);
        }

        return list;
    }

    void File::save(std::list<uint8_t> *data)
    {
    }
}
