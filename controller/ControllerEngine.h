#pragma once
#include <string>

class ControllerEngine
{
public:

    void startWorkflowA();

    void startWorkflowB();

    void startBatchWorkflow(int wafers);

    void sendCommand(
        const std::string& command);
};