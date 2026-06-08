#pragma once
#include <string>

class SimulationLogger
{
public:
    SimulationLogger();
    void logEvent(
        const std::string& waferId,
        const std::string& operation,
        const std::string& source,
        const std::string& destination,
        const std::string& status,
        int sequence);
};