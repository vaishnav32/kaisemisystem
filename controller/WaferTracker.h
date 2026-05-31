#pragma once

#include <string>
#include <unordered_map>

class WaferTracker
{
private:
    std::unordered_map<std::string,std::string> locations;

public:
    void updateLocation(
        const std::string& waferId,
        const std::string& location);

    std::string getLocation(
        const std::string& waferId);
};