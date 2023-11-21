#pragma once

#include "StateStorage.hpp"

namespace totksavs::core {
    class StateLevel1 : public StateStorage {
        public:
            void ReadFromGame() override;
            void WriteToGame() override;
            void ReadFromFile(fs::ConfigFile& file, u32 version) override;
            void WriteToFile(fs::ConfigFile& file) const override;

        private:
            u32 mHealth;
            f32 mStamina;
            f32 mMainPositionMatrix[12];

            // TODO: Haven't found these pointers yet
            // f32 mHavokPosition[3];
            // f32 mCameraPanMatrix[12];
            // f32 mCameraZoom;
            // f32 mCameraTilt;
    };
}  // namespace totksavs::core
