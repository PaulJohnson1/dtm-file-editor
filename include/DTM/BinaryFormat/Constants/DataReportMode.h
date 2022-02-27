#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>

namespace tas::dtm::binary::constants::DataReportMode
{
    enum
    {
        Buttons = 0x30,
        Buttons_Accelerometer = 0x31,
        Buttons_8ExtensionBytes = 0x32,
        Buttons_Accelerometer_IrBytes12 = 0x33,
        Buttons_ExtensionBytes19 = 0x34,
        Buttons_Accelerometer_ExtensionBytes16 = 0x35,
        Buttons_IrBytes10_ExtensionBytes9 = 0x36,
        Buttons_Accelerometer_IrBytes10_ExtensionBytes6 = 0x37,
        ExtensionBytes21 = 0x3d,
    };

    // std::unordered_map<uint8_t, std::string> inverse = {
    //     {0x30, "Buttons"},
    //     {0x31, "Buttons_Accelerometer"},
    //     {0x32, "Buttons_8ExtensionBytes"},
    //     {0x33, "Buttons_Accelerometer_IrBytes12"},
    //     {0x34, "Buttons_ExtensionBytes19"},
    //     {0x35, "Buttons_Accelerometer_ExtensionBytes16"},
    //     {0x36, "Buttons_IrBytes10_ExtensionBytes9"},
    //     {0x37, "Buttons_Accelerometer_IrBytes10_ExtensionBytes6"},
    //     {0x3d, "ExtensionBytes21"},
    // };
}
