#pragma once

#include <vector>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

#include <DTM/DecodedDTMFile.h>
#include <GUI/Component/FramesList.h>
#include <GUI/Layout.h>
#include <Util/File.h>

namespace tas::input_gui
{
    class MainWindow
    {
    public:
        QMainWindow *mainWindow;
        QWidget *centralWidget;
        dtm::DecodedDTMFile dtmFile;
        Ui_Form layout;

        MainWindow();
        ~MainWindow();
    private:
        FramesList frames;
        void renderDtmFile();
    };
}
