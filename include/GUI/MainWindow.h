#pragma once

#include <QAction>
#include <QMainWindow>
#include <QMenu>

namespace tas::input_gui
{
    class MainWindow : public QMainWindow
    {
    public:
        MainWindow();
        ~MainWindow();
    private:
        QAction *actionOpenDTMFile;
        QMenu *menuFile;
        
        void onOpenDTMFile();
        void initializeActions();
        void initializeWidgets();
        void initializeMenuBar();
    };
}
