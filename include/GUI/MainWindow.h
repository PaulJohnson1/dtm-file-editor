#pragma once

#include <vector>

#include <QMainWindow>

#include <DTM/DecodedDTMFile.h>
#include <Util/File.h>

namespace tas::input_gui
{
    class MainWindow : public QMainWindow
    {
    public:
        dtm::DecodedDTMFile dtmFile;

        MainWindow();
        ~MainWindow();
    private:
        void renderDtmFile();
    };
}
