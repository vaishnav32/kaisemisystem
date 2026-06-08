#include "SimulationManager.h"

#include <iostream>

int main()
{
    SimulationManager sim;

    int choice;

    std::cout << "================================\n";
    std::cout << "KAISEMI WAFER ROBOT SIMULATION\n";
    std::cout << "================================\n";

    std::cout << "\n1. Workflow A\n";
    std::cout << "2. Workflow B\n";
    std::cout << "3. Batch Workflow\n";

    std::cout << "\nEnter Choice: ";
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            sim.runWorkflowA();
            break;

        case 2:
            sim.runWorkflowB();
            break;

        case 3:
        {
            int wafers;

            std::cout
                << "Enter Number Of Wafers: ";

            std::cin >> wafers;

            sim.runBatchWorkflow(wafers);

            break;
        }

        default:
            std::cout
                << "Invalid Choice\n";
    }

    return 0;
}