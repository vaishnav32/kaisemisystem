#include "protocol.hpp"

#include <sstream>
#include <iomanip>
#include <stdexcept>

std::string calculateChecksum(const std::string& payload)
{
    unsigned char checksum = 0;

    for (char c : payload)
    {
        checksum ^= static_cast<unsigned char>(c);
    }

    std::stringstream ss;

    ss << std::uppercase
       << std::hex
       << std::setw(2)
       << std::setfill('0')
       << static_cast<int>(checksum);

    return ss.str();
}

std::string buildMessage(const std::string& payload)
{
    return std::string(1, '\x01') +
           payload +
           "|" +
           calculateChecksum(payload) +
           "\r\n";
}

bool validateMessage(const std::string& rawMessage)
{
    if (rawMessage.size() < 5)
        return false;

    if (rawMessage.front() != '\x01')
        return false;

    if (rawMessage.substr(rawMessage.size() - 2) != "\r\n")
        return false;

    std::string body =
        rawMessage.substr(1, rawMessage.size() - 3);

    size_t lastPipe = body.rfind('|');

    if (lastPipe == std::string::npos)
        return false;

    std::string payload =
        body.substr(0, lastPipe);

    std::string checksum =
        body.substr(lastPipe + 1);

    return calculateChecksum(payload) == checksum;
}

Message parseMessage(const std::string& rawMessage)
{
    if (!validateMessage(rawMessage))
    {
        throw std::runtime_error("Invalid message");
    }

    std::string body =
        rawMessage.substr(1, rawMessage.size() - 3);

    size_t lastPipe = body.rfind('|');

    std::string payload =
        body.substr(0, lastPipe);

    std::stringstream ss(payload);

    std::string token;

    std::vector<std::string> parts;

    while (std::getline(ss, token, '|'))
    {
        parts.push_back(token);
    }

    Message msg;

    msg.type = parts[0];
    msg.seq = std::stoi(parts[1]);

    for (size_t i = 2; i < parts.size(); i++)
    {
        msg.fields.push_back(parts[i]);
    }

    return msg;
}