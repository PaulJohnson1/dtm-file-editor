#include <GUI/MainWindow.h>

#include <iostream>

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <DTM/DecodedDTMFile.h>
#include <GUI/Component/FramesList.h>
#include <Util/File.h>

namespace tas::input_gui
{
    MainWindow::MainWindow() : mainWindow(new QMainWindow()),
                               dtmFile(dtm::DecodedDTMFile(dtm::File::open(mainWindow))),
                               centralWidget(new QWidget()),
                               frames(FramesList(mainWindow, centralWidget, &this->dtmFile))
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
