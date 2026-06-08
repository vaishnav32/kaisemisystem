#include "SimulationLogger.h"

#include <fstream>
#include <ctime>

SimulationLogger::SimulationLogger()
{
    std::ofstream file(
        "simulation_log.csv");

    file
        << "Timestamp,"
        << "WaferID,"
        << "Operation,"
        << "Source,"
        << "Destination,"
        << "Status,"
        << "Sequence\n";
}

void SimulationLogger::logEvent(
    const std::string& waferId,
    const std::string& operation,
    const std::string& source,
    const std::string& destination,
    const std::string& status,
    int sequence)
{
    std::ofstream file(
        "simulation_log.csv",
        std::ios::app);

    std::time_t now =
        std::time(nullptr);

    char timeBuffer[100];

    std::strftime(
        timeBuffer,
        sizeof(timeBuffer),
        "%Y-%m-%d %H:%M:%S",
        std::localtime(&now));

    file
        << timeBuffer << ","
        << waferId << ","
        << operation << ","
        << source << ","
        << destination << ","
        << status << ","
        << sequence
        << "\n";
}