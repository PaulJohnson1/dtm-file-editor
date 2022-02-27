#pragma once

#include <cstdint>

namespace tas::dtm::binary
{
    enum class EmulationLevel
    {
        low,
        high
    };

    enum class CPUCore
    {
        interpreter,
        jit,
        jitil
    };

    /**
     * https://tasvideos.org/EmulatorResources/DTM
     */
    struct Header
    {
    public:
        uint32_t signature;
        char gameId[6];
        bool isWiiGame;
        uint8_t controllersPluggedIn;
        bool startsFromSaveState;
        uint64_t viCount;
        uint64_t inputCount;
        uint64_t lagCount;
        char reserved_0[8];
        uint32_t rerecordCount;
        char author[32];
        char videoBackend[16];
        char audioEmulator[16];
        char gameHash[16];
        uint64_t recordingStartTime;
        bool savedConfigValid;
        bool idleSkipping;
        bool dualCoresEnabled;
        char emulationLevel;
        bool fastDiscSpeedup;
        char cpuCore;
        bool efbAccess;
        bool efbCopy;
        bool copyEfbToTexture;
        bool efbCopyCache;
        bool emulateFormatChanges;
        bool useXfbEmulation;
        bool useRealXfbEmulation;
        uint8_t memoryCards;
        bool blankMemoryCard;
        uint8_t bongosPluggedIn;
        bool syncGPUTread;
        bool rerecordedInNetplay;
        bool pal60;
        uint32_t lanuage;
        char reserved_1[1];
        bool jitBranchFollowing;
        char reserved_2[9];
        char secondIsoDiscName[40];
        uint8_t gitRevisionHash[20];
        int32_t dspIromHash;
        int32_t dspCoefHash;
        uint64_t tickCount;
        char reserved_3[11];
    };
}
