#pragma once

#include "StringBuffer.hpp"

namespace totksavs::util {
using TimeBuffer = StringBuffer<20>;
/**
 * Get current time as string, format YYYY-MM-DD HH:MM:SS
 */
void CurrentTimeString(TimeBuffer& outBuffer);
}  // namespace totksavs::util
