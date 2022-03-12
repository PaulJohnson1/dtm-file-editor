#pragma once

#include <vector>

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>

#include <DTM/DecodedDTMFile.h>
#include <GUI/Layout.h>

namespace tas::input_gui
{
    class FramesList
    {
    private:
        QMainWindow *parent;
        Ui_Form *layout;

        std::vector<QTableWidgetItem *> tableItemPointers;
        dtm::DecodedDTMFile *dtmFile;

    public:
        FramesList(QMainWindow *parentl, dtm::DecodedDTMFile *dtmFile, Ui_Form *layout);
        ~FramesList();
        void renderFrames();
    };
}
