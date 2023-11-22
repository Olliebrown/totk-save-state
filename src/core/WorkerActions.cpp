#include "Worker.hpp"
#include "fs/Logger.hpp"

namespace totksavs::core {
    bool Worker::Work() {
        debug("Work requested");
        return true;
    }
}  // namespace totksavs::core
