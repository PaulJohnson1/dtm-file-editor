#include <GUI/MainWindow.h>

#include <iostream>

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>

namespace tas::input_gui
{
    MainWindow::MainWindow()
    {
        initializeMenuBar();
    }

    MainWindow::~MainWindow()
    {
    }

    void MainWindow::initializeActions()
    {
        actionOpenDTMFile = new QAction(tr("&Open..."), this);

        actionOpenDTMFile->setShortcut(Qt::Modifier::CTRL + Qt::Key::Key_O);

        connect(actionOpenDTMFile, &QAction::triggered, this, &MainWindow::onOpenDTMFile);
    }

    void MainWindow::onOpenDTMFile()
    {
    }

    void MainWindow::initializeMenuBar()
    {
        initializeActions();
        
        menuFile = menuBar()->addMenu(tr("&File"));
        menuFile->addAction(actionOpenDTMFile);
    }
}
