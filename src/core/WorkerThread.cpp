#include "WorkerThread.hpp"
#include <mem.h>
#include <nn/os.h>
#include <nn/time.h>
#include "Worker.hpp"
#include "fs/File.hpp"
#include "fs/Logger.hpp"

namespace totksavs::core {
    static nn::os::ThreadType sThread;

    void WorkerMain(void* arg) {
        debug(">> Worker thread main");

        nn::TimeSpan shortWait = nn::TimeSpan::FromNanoSeconds(100000000);  // 3f
        nn::TimeSpan longWait = nn::TimeSpan::FromSeconds(5);

        Worker worker;
        if (!worker.Init()) {
            error(">> Worker init failed");
        }

        while (true) {
            debug(">> Worker thread working");
            bool success = worker.Work();

            nn::os::YieldThread();  // let other parts of OS do their thing
            if (!success) {
                debug(">> Worker thread long sleeping");
                nn::os::SleepThread(longWait);
            } else {
                debug(">> Worker thread short sleeping");
                nn::os::SleepThread(shortWait);
            }
        }

        debug(">> Worker thread stopping");
    }

    void StartWorkerThread() {
        debug("Worker thread setup:");
        const size_t stackSize = 0x80000;
        void* threadStack = memalign(0x1000, stackSize);

        debug("-- Creating thread");
        sThread.thread_name_addr = "totksavs";
        nn::Result result =
            nn::os::CreateThread(&sThread, WorkerMain, nullptr, threadStack, stackSize, 16, 0);
        if (result.IsFailure()) {
            return;
        }

        debug("-- Starting thread execution");
        nn::os::StartThread(&sThread);
    }
}  // namespace totksavs::core
