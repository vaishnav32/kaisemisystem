#pragma once

#include "controller/ControllerEngine.h"
#include "controller/ResponseHandler.h"
#include "controller/WaferTracker.h"
#include "SimulationLogger.h"
#include <vector>
#include <queue>

class SimulationManager
{
private:
    ControllerEngine controller;
    ResponseHandler responseHandler;
    WaferTracker tracker;
    SimulationLogger logger;

    std::vector<std::string> upperArm;
    std::vector<std::string> lowerArm;
    std::queue<std::string> waferQueue;

    void simulateCommand(
        const std::string& waferId,
        int seq,
        const std::string& operation,
        const std::string& from,
        const std::string& to);

public:
    void runWorkflowA();
    void runWorkflowB();
    void runBatchWorkflow(int wafers);
};