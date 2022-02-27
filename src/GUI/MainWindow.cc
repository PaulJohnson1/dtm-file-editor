#include <GUI/MainWindow.h>

#include <iostream>

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>

#include <GUI/Component/File.h>

namespace tas::input_gui
{
    MainWindow::MainWindow() : fileManagerComponent(dtm::File(this)) 
    {
        initializeMenuBar();
    }

    MainWindow::~MainWindow()
    {
        delete actionOpenDTMFile;
    }

    void MainWindow::initializeActions()
    {
        actionOpenDTMFile = new QAction(tr("&Open..."), this);

        actionOpenDTMFile->setShortcut(Qt::Modifier::CTRL | Qt::Key::Key_O);

        connect(actionOpenDTMFile, &QAction::triggered, this, &MainWindow::onOpenDTMFile);
    }

    void MainWindow::onOpenDTMFile()
    {
        fileManagerComponent.open();
    }

    void MainWindow::initializeMenuBar()
    {
        initializeActions();
        
        menuFile = menuBar()->addMenu(tr("&File"));
        menuFile->addAction(actionOpenDTMFile);
    }
}
