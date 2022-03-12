#pragma once

#include <QTreeWidgetItem>
#include <QMainWindow>

#include <GUI/Layout.h>
#include <DTM/BinaryFormat/DataFrame.h>

namespace tas::input_gui
{
    class Frame
    {
    private:
        Ui_Form *parentLayout;
        QMainWindow *parentWindow;

    public:
        QTreeWidgetItem *qItem;
        
        Frame(Ui_Form *parentLayout, QMainWindow *parentWindow, dtm::binary::DataFrame &frame);
        void show();
        void onClick(const QTreeWidgetItem &index);
    };
}
