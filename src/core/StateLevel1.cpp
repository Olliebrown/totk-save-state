#include "StateLevel1.hpp"
#include "fs/ConfigFile.hpp"
#include "mem/GamePtr.h"

// We deliberately poke in memory we shouldn't so this warning is expected (and ignored)
#pragma GCC diagnostic ignored "-Warray-bounds"

namespace totksavs::core {
    void StateLevel1::ReadFromGame() {
        ReadMemory(named(mem::GamePtr::Health()), &mHealth);
        ReadMemory(named(mem::GamePtr::Stamina()), &mStamina);
        ReadMemoryArray(named(mem::GamePtr::MainPositionMatrix()), mMainPositionMatrix, 12);

        // TODO: Haven't found these pointers yet
        // ReadMemoryArray(named(mem::GamePtr::HavokPosition()), mHavokPosition, 3);
        // ReadMemoryArray(named(mem::GamePtr::CameraPanMatrix()), mCameraPanMatrix, 12);
        // ReadMemory(named(mem::GamePtr::CameraZoom()), &mCameraZoom);
        // ReadMemory(named(mem::GamePtr::CameraTilt()), &mCameraTilt);
    }

    void StateLevel1::WriteToGame() {
        WriteMemory(named(mem::GamePtr::Health()), mHealth);
        WriteMemory(named(mem::GamePtr::Stamina()), mStamina);
        WriteMemoryArray(named(mem::GamePtr::MainPositionMatrix()), mMainPositionMatrix, 12);

        // TODO: Haven't found these pointers yet
        // WriteMemoryArray(named(mem::GamePtr::HavokPosition()), mHavokPosition, 3);
        // WriteMemoryArray(named(mem::GamePtr::CameraPanMatrix()), mCameraPanMatrix, 12);
        // WriteMemory(named(mem::GamePtr::CameraZoom()), mCameraZoom);
        // WriteMemory(named(mem::GamePtr::CameraTilt()), mCameraTilt);
    }

    void StateLevel1::ReadFromFile(fs::ConfigFile& file, u32 version) {
        if (version < 1) { return; }
        file.ReadInteger(&mHealth);
        file.ReadFloat(&mStamina);
        file.ReadFloatArray(mMainPositionMatrix, 12);

        // TODO: Haven't found these pointers yet
        // file.ReadFloatArray(mHavokPosition, 3);
        // file.ReadFloatArray(mCameraPanMatrix, 12);
        // file.ReadFloat(&mCameraZoom);
        // file.ReadFloat(&mCameraTilt);
    }

    void StateLevel1::WriteToFile(fs::ConfigFile& file) const {
        file.WriteInteger(named(mHealth));
        file.WriteFloat(named(mStamina));
        file.WriteFloatArray(named(mMainPositionMatrix), 12);

        // TODO: Haven't found these pointers yet
        // file.WriteFloatArray(named(mHavokPosition), 3);
        // file.WriteFloatArray(named(mCameraPanMatrix), 12);
        // file.WriteFloat(named(mCameraZoom));
        // file.WriteFloat(named(mCameraTilt));
    }
}  // namespace totksavs::core
