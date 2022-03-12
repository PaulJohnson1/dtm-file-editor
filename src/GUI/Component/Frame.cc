#include <DTM/BinaryFormat/DataFrame.h>

#include <QAction>
#include <QTreeWidgetItem>
#include <QMainWindow>

#include <GUI/Component/Frame.h>
#include <GUI/Layout.h>

namespace tas::input_gui
{
    Frame::Frame(Ui_Form *parentLayout, QMainWindow *parentWindow, dtm::binary::DataFrame &frame)
        : parentLayout(parentLayout),
          parentWindow(parentWindow),
          qItem(new QTreeWidgetItem(parentLayout->treeWidget))
    {
        parentLayout->treeWidget->insertTopLevelItem(frame.inputIndex, qItem);
        qItem->setText(0, std::to_string(frame.inputIndex).c_str());
    }

    // void Frame::onClick()
    // {
    // }
}
