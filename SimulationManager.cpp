#include "SimulationManager.h"
#include "common/protocol.hpp"

#include <iostream>

void SimulationManager::simulateCommand(
    const std::string& waferId,
    int seq,
    const std::string& operation,
    const std::string& from,
    const std::string& to)
{
    std::string payload;

    if(operation == "PICK")
    {
        payload =
            "CMD|" +
            std::to_string(seq) +
            "|PICK|FROM=" +
            from;
    }
    else
    {
        payload =
            "CMD|" +
            std::to_string(seq) +
            "|PLACE|TO=" +
            to;
    }

    std::string message =
        buildMessage(payload);

    validateMessage(message);

    parseMessage(message);

    logger.logEvent(
        waferId,
        operation,
        from,
        to,
        "SUCCESS",
        seq
    );

    if(operation == "PICK")
    {
        std::cout
            << "Picking wafer from "
            << from
            << std::endl;
    }
    else
    {
        std::cout
            << "Placing wafer to "
            << to
            << std::endl;
    }
}

void SimulationManager::runWorkflowA()
{
    std::cout << "\n================================\n";
    std::cout << "Workflow A Started\n";
    std::cout << "================================\n";

    tracker.updateLocation(
        "WAFER1",
        "LPA1");

    std::cout << "\nCurrent Location:\n";

    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PICK FROM LPA1

    std::string payload =
        "CMD|101|PICK|FROM=LPA1";

    std::string message =
        buildMessage(payload);

    if(validateMessage(message))
    {
        std::cout
            << "Protocol Validation: SUCCESS\n";
    }
    else
    {
        std::cout
            << "Protocol Validation: FAILED\n";
    }

    std::cout << "\nSending Command:\n";
    std::cout << message << std::endl;

    responseHandler.handleMessage("ACK|101");
    responseHandler.handleMessage("STAT|101|BUSY");
    responseHandler.handleMessage("EVT|101|PICK_DONE");
    responseHandler.handleMessage("STAT|101|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "LOWER_ARM");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PLACE TO ALIGNER

    std::cout << "\nSending Command:\n";
    std::cout << "CMD|102|PLACE|TO=ALIGNER\n";

    responseHandler.handleMessage("ACK|102");
    responseHandler.handleMessage("STAT|102|BUSY");
    responseHandler.handleMessage("EVT|102|PLACE_DONE");
    responseHandler.handleMessage("STAT|102|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "ALIGNER");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PICK FROM ALIGNER

    std::cout << "\nSending Command:\n";
    std::cout << "CMD|103|PICK|FROM=ALIGNER\n";

    responseHandler.handleMessage("ACK|103");
    responseHandler.handleMessage("STAT|103|BUSY");
    responseHandler.handleMessage("EVT|103|PICK_DONE");
    responseHandler.handleMessage("STAT|103|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "LOWER_ARM");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PLACE TO PROCESS CHAMBER

    std::cout << "\nSending Command:\n";
    std::cout << "CMD|104|PLACE|TO=PROCESS_CHAMBER\n";

    responseHandler.handleMessage("ACK|104");
    responseHandler.handleMessage("STAT|104|BUSY");
    responseHandler.handleMessage("EVT|104|PLACE_DONE");
    responseHandler.handleMessage("STAT|104|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "PROCESS_CHAMBER");

    std::cout << "\nFinal Location:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    std::cout << "\nWorkflow A Completed\n";
}

void SimulationManager::runWorkflowB()
{
    std::cout << "\n================================\n";
    std::cout << "Workflow B Started\n";
    std::cout << "================================\n";

    tracker.updateLocation(
        "WAFER1",
        "PROCESS_CHAMBER");

    std::cout << "\nCurrent Location:\n";

    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PICK FROM PROCESS CHAMBER

    std::string payload =
        "CMD|201|PICK|FROM=PROCESS_CHAMBER";

    std::string message =
        buildMessage(payload);

    if(validateMessage(message))
    {
        std::cout
            << "Protocol Validation: SUCCESS\n";
    }
    else
    {
        std::cout
            << "Protocol Validation: FAILED\n";
    }

    std::cout << "\nSending Command:\n";
    std::cout << message << std::endl;

    responseHandler.handleMessage("ACK|201");
    responseHandler.handleMessage("STAT|201|BUSY");
    responseHandler.handleMessage("EVT|201|PICK_DONE");
    responseHandler.handleMessage("STAT|201|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "LOWER_ARM");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PLACE TO ALIGNER

    payload =
        "CMD|202|PLACE|TO=ALIGNER";

    message =
        buildMessage(payload);

    if(validateMessage(message))
    {
        std::cout
            << "Protocol Validation: SUCCESS\n";
    }
    else
    {
        std::cout
            << "Protocol Validation: FAILED\n";
    }

    std::cout << "\nSending Command:\n";
    std::cout << message << std::endl;

    responseHandler.handleMessage("ACK|202");
    responseHandler.handleMessage("STAT|202|BUSY");
    responseHandler.handleMessage("EVT|202|PLACE_DONE");
    responseHandler.handleMessage("STAT|202|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "ALIGNER");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PICK FROM ALIGNER

    payload =
        "CMD|203|PICK|FROM=ALIGNER";

    message =
        buildMessage(payload);

    if(validateMessage(message))
    {
        std::cout
            << "Protocol Validation: SUCCESS\n";
    }
    else
    {
        std::cout
            << "Protocol Validation: FAILED\n";
    }

    std::cout << "\nSending Command:\n";
    std::cout << message << std::endl;

    responseHandler.handleMessage("ACK|203");
    responseHandler.handleMessage("STAT|203|BUSY");
    responseHandler.handleMessage("EVT|203|PICK_DONE");
    responseHandler.handleMessage("STAT|203|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "LOWER_ARM");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    // PLACE TO LPA1

    payload =
        "CMD|204|PLACE|TO=LPA1";

    message =
        buildMessage(payload);

    if(validateMessage(message))
    {
        std::cout
            << "Protocol Validation: SUCCESS\n";
    }
    else
    {
        std::cout
            << "Protocol Validation: FAILED\n";
    }

    std::cout << "\nSending Command:\n";
    std::cout << message << std::endl;

    responseHandler.handleMessage("ACK|204");
    responseHandler.handleMessage("STAT|204|BUSY");
    responseHandler.handleMessage("EVT|204|PLACE_DONE");
    responseHandler.handleMessage("STAT|204|IDLE");

    tracker.updateLocation(
        "WAFER1",
        "LPA1");

    std::cout << "\nLocation Updated:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    std::cout << "\nFinal Location:\n";
    std::cout << "WAFER1 -> "
              << tracker.getLocation("WAFER1")
              << std::endl;

    std::cout << "\nWorkflow B Completed\n";
}

void SimulationManager::runBatchWorkflow(int wafers)
{
    std::cout << "\n================================\n";
    std::cout << "Batch Workflow Started\n";
    std::cout << "================================\n";

    while(!waferQueue.empty())
    {
        waferQueue.pop();
    }

    for(int i = 1; i <= wafers; i++)
    {
        waferQueue.push(
            "WAFER" +
            std::to_string(i));
    }

    int batchNumber = 1;

    while(!waferQueue.empty())
    {
        upperArm.clear();
        lowerArm.clear();

        std::cout
            << "\n================================\n";

        std::cout
            << "BATCH "
            << batchNumber
            << std::endl;

        std::cout
            << "================================\n";

        int remaining =
            waferQueue.size();

        if(remaining == 1)
        {
            lowerArm.push_back(
                waferQueue.front());

            waferQueue.pop();
        }
        else if(remaining <= 5)
        {
            while(!waferQueue.empty())
            {
                upperArm.push_back(
                    waferQueue.front());

                waferQueue.pop();
            }
        }
        else
        {
            for(int i = 0; i < 5; i++)
            {
                upperArm.push_back(
                    waferQueue.front());

                waferQueue.pop();
            }

            lowerArm.push_back(
                waferQueue.front());

            waferQueue.pop();
        }

        std::cout
            << "\nUPPER_ARM:\n";

        if(upperArm.empty())
        {
            std::cout
                << "EMPTY\n";
        }

        for(const auto& wafer : upperArm)
        {
            std::cout
                << wafer
                << std::endl;
        }

        std::cout
            << "\nLOWER_ARM:\n";

        if(lowerArm.empty())
        {
            std::cout
                << "EMPTY\n";
        }

        for(const auto& wafer : lowerArm)
        {
            std::cout
                << wafer
                << std::endl;
        }

        if(!waferQueue.empty())
        {
            std::cout
                << "\n*** MAXIMUM CAPACITY REACHED ***\n";

            std::cout
                << "Remaining Wafers: "
                << waferQueue.size()
                << std::endl;
        }

        std::cout
            << "\nProcessing Upper Arm Wafers...\n";

        int seq = 500;

        for(const auto& wafer : upperArm)
        {
            tracker.updateLocation(
                wafer,
                "LPA1");

            simulateCommand(
                wafer,
                seq++,
                "PICK",
                "LPA1",
                "");

            simulateCommand(
                wafer,
                seq++,
                "PLACE",
                "",
                "PROCESS_CHAMBER");

            tracker.updateLocation(
                wafer,
                "PROCESS_CHAMBER");

            std::cout
                << wafer
                << " -> PROCESS_CHAMBER\n";
        }

        std::cout
            << "\nProcessing Lower Arm Wafers...\n";

        for(const auto& wafer : lowerArm)
        {
            tracker.updateLocation(
                wafer,
                "LPA1");

            simulateCommand(
                wafer,
                seq++,
                "PICK",
                "LPA1",
                "");

            simulateCommand(
                wafer,
                seq++,
                "PLACE",
                "",
                "PROCESS_CHAMBER");

            tracker.updateLocation(
                wafer,
                "PROCESS_CHAMBER");

            std::cout
                << wafer
                << " -> PROCESS_CHAMBER\n";
        }

        batchNumber++;
    }

    std::cout
        << "\n================================\n";

    std::cout
        << "ALL BATCHES COMPLETED\n";

    std::cout
        << "================================\n";
}