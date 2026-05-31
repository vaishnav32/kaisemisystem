#include "ResponseHandler.h"
#include <iostream>

void ResponseHandler::handleMessage(
    const std::string& msg)
{
    std::cout << "Received: "
              << msg
              << std::endl;
}