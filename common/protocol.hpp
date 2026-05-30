#pragma once

#include <string>
#include <vector>

struct Message
{
    std::string type;
    int seq;
    std::vector<std::string> fields;
};

std::string calculateChecksum(const std::string& payload);

std::string buildMessage(const std::string& payload);

bool validateMessage(const std::string& rawMessage);

Message parseMessage(const std::string& rawMessage);