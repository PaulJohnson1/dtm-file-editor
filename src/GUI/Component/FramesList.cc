#include <GUI/Component/FramesList.h>

#include <iostream>
#include <vector>

#include <QMainWindow>

#include <DTM/DecodedDTMFile.h>
#include <GUI/Component/Frame.h>
#include <GUI/Layout.h>

namespace tas::input_gui
{
    FramesList::FramesList(QMainWindow *parent, dtm::DecodedDTMFile *dtmFile, Ui_Form *layout)
        : parent(parent),
          dtmFile(dtmFile),
          layout(layout)
    {
        layout->setupUi(parent);
    }

    FramesList::~FramesList()
    {
    }

    void FramesList::renderFrames()
    {
        std::vector<Frame *> frames{};

        for (size_t i = 0; i < dtmFile->reader.frames.size(); i++)
        {
            std::cout << "rendering input poll " << i << std::endl;
            Frame *frame = new Frame(layout, parent, dtmFile->reader.frames.at(i));
            frames.push_back(frame);
        }
    }
}
