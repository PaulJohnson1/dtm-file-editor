#include <DTM/BinaryFormat/Header.h>

#include <algorithm>
#include <cstddef>
#include <cstdint>

#include <Util/ReadMemoryOffsetAs.h>

namespace tas::dtm::binary
{
    Header::Header()
    {
    }

    void Header::operator=(uint8_t *bytes)
    {
        signature = util::readMemoryOffsetAs<uint32_t>(bytes, 0x00);
        isWiiGame = bytes[0x0a];
        controllersPluggedIn = bytes[0x0b];
        startsFromSaveState = bytes[0x0c];
        viCount = util::readMemoryOffsetAs<uint64_t>(bytes, 0x0d);
        inputCount = util::readMemoryOffsetAs<uint64_t>(bytes, 0x15);
        lagCount = util::readMemoryOffsetAs<uint64_t>(bytes, 0x1d);
        rerecordCount = util::readMemoryOffsetAs<uint32_t>(bytes, 0x2d);
        recordingStartTime = util::readMemoryOffsetAs<uint64_t>(bytes, 0x81);
        savedConfigValid = bytes[0x89];
        idleSkipping = bytes[0x8a];
        dualCoresEnabled = bytes[0x8b];
        progressiveScanning = bytes[0x8c];
        emulationLevel = bytes[0x8d];
        fastDiscSpeedup = bytes[0x8e];
        cpuCore = bytes[0x8f];
        efbAccess = bytes[0x90];
        efbCopy = bytes[0x91];
        copyEfbToTexture = bytes[0x92];
        efbCopyCache = bytes[0x93];
        emulateFormatChanges = bytes[0x94];
        useXfbEmulation = bytes[0x95];
        useRealXfbEmulation = bytes[0x96];
        memoryCards = bytes[0x97];
        blankMemoryCard = bytes[0x98];
        bongosPluggedIn = bytes[0x99];
        syncGPUTread = bytes[0x9a];
        rerecordedInNetplay = bytes[0x9b];
        pal60 = bytes[0x9c];
        lanuage = bytes[0x9d];
        jitBranchFollowing = bytes[0x9f];
        dspIromHash = util::readMemoryOffsetAs<uint32_t>(bytes, 0xe5);
        dspCoefHash = util::readMemoryOffsetAs<uint32_t>(bytes, 0xe9);
        tickCount = util::readMemoryOffsetAs<uint64_t>(bytes, 0xed);

        std::copy(bytes + 0x04, bytes + 0x04 + 6, gameId);
        std::copy(bytes + 0x31, bytes + 0x31 + 32, author);
        std::copy(bytes + 0x51, bytes + 0x51 + 16, videoBackend);
        std::copy(bytes + 0x61, bytes + 0x61 + 16, audioEmulator);
        std::copy(bytes + 0x71, bytes + 0x71 + 16, gameHash);
        std::copy(bytes + 0xa9, bytes + 0xa0 + 40, secondIsoDiscName);
        std::copy(bytes + 0xd1, bytes + 0xd1 + 20, gitRevisionHash);
    }
}
