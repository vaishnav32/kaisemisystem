#include "ControllerEngine.h"
#include <iostream>

void ControllerEngine::startWorkflowA()
{
    std::cout
    << "Workflow A Started"
    << std::endl;
}

void ControllerEngine::startWorkflowB()
{
    std::cout
    << "Workflow B Started"
    << std::endl;
}

void ControllerEngine::startBatchWorkflow(
    int wafers)
{
    std::cout
    << "Batch Workflow Started : "
    << wafers
    << std::endl;
}