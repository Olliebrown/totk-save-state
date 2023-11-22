#pragma once

#define WORKER_TXT_PATH "sd:/totksavs/worker.txt"

namespace totksavs { namespace core {
    class Worker {
        public:
            bool Init();
            bool Work();
    };
}  /* namespace core */ }  /* namespace totksavs */
