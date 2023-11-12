#include "main.hpp"
#include "core/WorkerThread.hpp"
#include "fs/File.hpp"
#include "fs/Logger.hpp"

extern "C" void application_init() {
    nn::fs::MountSdCardForDebug("sd");
    // Create runtime files
#ifdef DEBUG
    totksavs::fs::File mainLog("sd:/totksavs/main.log");
    mainLog.Create();

    // Initialize Logger
    totksavs::fs::Logger::Instance().Init();
#endif
    totksavs::fs::File latestTxt("sd:/totksavs/latest.txt");
    latestTxt.Create();
    totksavs::fs::File workerTxt("sd:/totksavs/worker.txt");
    workerTxt.Create();

    // Start worker
    totksavs::core::StartWorkerThread();
}

extern "C" void application_clean() {
#ifdef DEBUG
    // Close logger
    totksavs::fs::Logger::Instance().Close();
#endif
}
