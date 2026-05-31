#include "WaferTracker.h"

void WaferTracker::updateLocation(
    const std::string& waferId,
    const std::string& location)
{
    locations[waferId] = location;
}

std::string WaferTracker::getLocation(
    const std::string& waferId)
{
    return locations[waferId];
}