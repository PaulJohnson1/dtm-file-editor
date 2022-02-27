#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenu>

#include <DTM/BinaryFormat/File.h>

namespace tas::input_gui
{
    class MainWindow : public QMainWindow
    {
    public:
        dtm::File fileManagerComponent;
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
