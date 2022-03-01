#include <GUI/MainWindow.h>

#include <iostream>

#include <QMainWindow>

#include <DTM/DecodedDTMFile.h>
#include <Util/File.h>

namespace tas::input_gui
{
    MainWindow::MainWindow() : dtmFile(dtm::DecodedDTMFile(dtm::File::open(this)))
    {
        renderDtmFile();
    }

    MainWindow::~MainWindow()
    {
    }

    void MainWindow::renderDtmFile()
    {
    }
}
