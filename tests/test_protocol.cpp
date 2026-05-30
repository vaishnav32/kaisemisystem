#include <iostream>

#include "../common/protocol.hpp"

int main()
{
    std::string payload =
        "CMD|101|PICK|FROM=LPA|ARM=LOWER";

    std::string message =
        buildMessage(payload);

    std::cout << "Generated Message:\n";
    std::cout << message << "\n";

    if (validateMessage(message))
    {
        std::cout << "\nMessage Valid\n";

        Message msg =
            parseMessage(message);

        std::cout << "\nType: "
                  << msg.type
                  << '\n';

        std::cout << "Seq : "
                  << msg.seq
                  << '\n';

        std::cout << "\nFields:\n";

        for (const auto& field : msg.fields)
        {
            std::cout << field << '\n';
        }
    }
    else
    {
        std::cout << "Message Invalid\n";
    }

    return 0;
}