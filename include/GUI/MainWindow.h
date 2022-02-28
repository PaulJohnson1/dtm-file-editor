#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenu>

#include <DTM/DecodedDTMFile.h>
#include <Util/File.h>

namespace tas::input_gui
{
    class MainWindow : public QMainWindow
    {
    public:
        dtm::DecodedDTMFile *dtmFile;
        QAction *actionOpenDTMFile;
        QMenu *menuFile;

        MainWindow();
        ~MainWindow();
    private:

        
        void onOpenDTMFile();
        void initializeActions();
        void initializeWidgets();
        void initializeMenuBar();
    };
}
