#include <iostream>

#include <QApplication>
#include <QMainWindow>

#include <GUI/MainWindow.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    tas::input_gui::MainWindow gui;
    gui.show();
    return app.exec();
}
