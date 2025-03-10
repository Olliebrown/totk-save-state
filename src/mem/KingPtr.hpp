#pragma once

#include "types.h"
namespace sead {
struct ControllerMgr;
}

/**
 * MAKE SURE TO UPDATE symbols.ld IF YOU CHANGE SOMETHING HERE
 *
 */
namespace totksavs::mem::KingPtr {

// main offset from mod 0x3483000
// 0x0
// _ZN8totksavs3mem7KingPtr10MainMemoryE
extern void* MainMemory;
// 0x2CBF658
// _ZN8totksavs3mem7KingPtr22sControllerMgrInstanceE
extern sead::ControllerMgr* sControllerMgrInstance;
// 0x1238680    (0000007100A95924) in 1.5.0
//_ZN8totksavs3mem7KingPtr25ShowInfoOverlayWithStringEmPKv
extern void* ShowInfoOverlayWithString(u64 idx, const void* p_sead__SafeString);
// 0x123DEA0
// _ZN8totksavs3mem7KingPtr16GetMessageStringEPvS2_S2_
extern u64 GetMessageString(void* file, void* messageId, void* outString);

// Other used:
// uking::ui::PauseMenuDataMgr::sInstance
// 0x02CA6D50
// _ZN5uking2ui16PauseMenuDataMgr9sInstanceE
//
}  // namespace totksavs::mem::KingPtr
