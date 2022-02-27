#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenu>

#include <DTM/Editor.h>
#include <GUI/Component/File.h>

namespace tas::input_gui
{
    class MainWindow : public QMainWindow
    {
    public:
        dtm::format::Editor file; 

        MainWindow();
        ~MainWindow();
    private:
        QAction *actionOpenDTMFile;
        QMenu *menuFile;
        dtm::File fileManagerComponent;

        
        void onOpenDTMFile();
        void initializeActions();
        void initializeWidgets();
        void initializeMenuBar();
    };
}
