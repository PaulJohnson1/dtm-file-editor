#pragma once

#include <vector>

#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>

#include <DTM/DecodedDTMFile.h>

namespace tas::input_gui
{
    class FramesList
    {
    private:
        QMainWindow *parent;
        QWidget *centralWidget;
        QTableWidget *tableWidget;
        QTableWidgetItem *rows[16];
        
        std::vector<QTableWidgetItem *> tableItemPointers;
        dtm::DecodedDTMFile *dtmFile;

    public:
        FramesList(QMainWindow *parent, QWidget *centralWidget, dtm::DecodedDTMFile *dtmFile);
        ~FramesList();
        void renderFrames();
        void initializeTable();
    };
}
