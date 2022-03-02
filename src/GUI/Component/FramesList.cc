#include <GUI/Component/FramesList.h>

#include <iostream>

#include <QApplication>
#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QtWidgets/QHeaderView>

#include <DTM/DecodedDTMFile.h>

namespace tas::input_gui
{
    FramesList::FramesList(QMainWindow *parent, QWidget *centralWidget, dtm::DecodedDTMFile *dtmFile)
        : parent(parent),
          centralWidget(new QWidget(parent)),
          tableWidget(new QTableWidget(centralWidget)),
          dtmFile(dtmFile)
    {
        initializeTable();
    }

    FramesList::~FramesList()
    {
        for (size_t i = 0; i < tableItemPointers.size(); i++)
        {
            delete tableItemPointers.at(i);
        }

        for (size_t i = 0; i < 16; i++)
        {
            delete rows[i];
        }
    }

    void FramesList::initializeTable()
    {
        if (parent->objectName().isEmpty())
            parent->setObjectName(QString::fromUtf8("parent"));
        parent->resize(992, 545);
        centralWidget = new QWidget(parent);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setRowCount(16);
        rows[0] = new QTableWidgetItem("Left");
        rows[1] = new QTableWidgetItem("Right");
        rows[2] = new QTableWidgetItem("Down");
        rows[3] = new QTableWidgetItem("Up");
        rows[4] = new QTableWidgetItem("Plus");
        rows[5] = new QTableWidgetItem("Accel X bit 0");
        rows[6] = new QTableWidgetItem("Accel X bit 1");
        rows[7] = new QTableWidgetItem("Unknown");
        rows[8] = new QTableWidgetItem("1");
        rows[9] = new QTableWidgetItem("2");
        rows[10] = new QTableWidgetItem("A");
        rows[11] = new QTableWidgetItem("B");
        rows[12] = new QTableWidgetItem("Minus");
        rows[13] = new QTableWidgetItem("Accel Y bit 1");
        rows[14] = new QTableWidgetItem("Accel Z bit 1");
        rows[15] = new QTableWidgetItem("Home");

        tableWidget->setVerticalHeaderItem(0, rows[0]);
        tableWidget->setVerticalHeaderItem(1, rows[1]);
        tableWidget->setVerticalHeaderItem(2, rows[2]);
        tableWidget->setVerticalHeaderItem(3, rows[3]);
        tableWidget->setVerticalHeaderItem(4, rows[4]);
        tableWidget->setVerticalHeaderItem(5, rows[5]);
        tableWidget->setVerticalHeaderItem(6, rows[6]);
        tableWidget->setVerticalHeaderItem(7, rows[7]);
        tableWidget->setVerticalHeaderItem(8, rows[8]);
        tableWidget->setVerticalHeaderItem(9, rows[9]);
        tableWidget->setVerticalHeaderItem(10, rows[10]);
        tableWidget->setVerticalHeaderItem(11, rows[11]);
        tableWidget->setVerticalHeaderItem(12, rows[12]);
        tableWidget->setVerticalHeaderItem(13, rows[13]);
        tableWidget->setVerticalHeaderItem(14, rows[14]);
        tableWidget->setVerticalHeaderItem(15, rows[15]);

        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(0, 0, 800, 360));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(15);
        tableWidget->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget->verticalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        parent->setCentralWidget(centralWidget);

        parent->setWindowTitle(QApplication::translate("parent", "parent", nullptr));

        QMetaObject::connectSlotsByName(parent);
    }

    void FramesList::renderFrames()
    {
        for (size_t i = 0; i < dtmFile->reader.frames.size(); i++)
        {
            std::bitset<16> &buttons = dtmFile->reader.frames.at(i).buttonFlags;

            std::cout << i << std::endl;
            dtm::binary::DataFrame &frame = dtmFile->reader.frames.at(i);
            // heap allocation in ordor to not overflow the stack
            QTableWidgetItem *item = new QTableWidgetItem(std::to_string(i).c_str());
            tableItemPointers.push_back(item);
            tableWidget->setColumnCount(i + 1);
            tableWidget->setHorizontalHeaderItem(i, item);

            for (size_t j = 0; j < 16; j++)
            {
                QTableWidgetItem *checkStatus = new QTableWidgetItem();
                tableItemPointers.push_back(checkStatus);
                if (buttons.test(j))
                    checkStatus->setCheckState(Qt::Checked);
                else
                    checkStatus->setCheckState(Qt::Unchecked);
                tableWidget->setItem(j, i, checkStatus);
            }
        }
    }
}
