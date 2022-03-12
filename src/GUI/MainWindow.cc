#include <GUI/MainWindow.h>

#include <iostream>

#include <QMainWindow>
#include <QWidget>

#include <DTM/DecodedDTMFile.h>
#include <GUI/Component/FramesList.h>
#include <GUI/Layout.h>

#include <Util/File.h>

namespace tas::input_gui
{
    MainWindow::MainWindow() : mainWindow(new QMainWindow()),
                               dtmFile(dtm::DecodedDTMFile(dtm::File::open(mainWindow))),
                               centralWidget(new QWidget()),
                               layout(Ui_Form()),
                               frames(FramesList(mainWindow, &this->dtmFile, &layout))

    {
        renderDtmFile();
        mainWindow->show();
    }

    MainWindow::~MainWindow()
    {
        delete dtmFile.file;
        delete mainWindow;
        delete centralWidget;
    }

    void MainWindow::renderDtmFile()
    {
        frames.renderFrames();
    }
}
