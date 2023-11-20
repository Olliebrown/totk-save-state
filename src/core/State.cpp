#include "State.hpp"

namespace totksavs::core {
    bool State::ReadFromGame(u32 level) {
        ClearError();
        switch (level) {
            case 1:
                mStorageLevel1.ReadFromGame();
                break;
            default:
                errorf("Bad state level: %d", level);
                break;
        }
        mLevel = level;
        return !HasAnyError();
    }

    bool State::WriteToGame(u32 level) {
        if (mLevel < level) {
            return false;
        }
        ClearError();
        switch (level) {
            case 1:
                mStorageLevel1.WriteToGame();
                break;
            default:
                errorf("Bad state level: %d", level);
                break;
        }
        return !HasAnyError();
    }

    bool State::CanReadFromFile() {
        return fs::ConfigFile(RESTORE_TXT_PATH).Exists();
    }

    bool State::ReadFromFile() {
        return fs::ConfigFile(RESTORE_TXT_PATH).Load(*this);
    }

    bool State::WriteToFile() const {
        return fs::ConfigFile(LATEST_TXT_PATH).Save(*this);
    }

    void State::Load(fs::ConfigFile& file) {
        u32 version = 0;
        file.ReadInteger(&version);
        file.ReadInteger(&mLevel);

        if (version < 1 || version > STATE_SAVE_FILE_VERSION) {
            errorf("Bad version: %d", version);
            return;
        }

        mStorageLevel1.ReadFromFile(file, version);
    }

    void State::Save(fs::ConfigFile& file) const {
        file.WriteInteger("version", STATE_SAVE_FILE_VERSION);
        file.WriteInteger(named(mLevel));

        mStorageLevel1.WriteToFile(file);
    }
}  // namespace totksavs::core
