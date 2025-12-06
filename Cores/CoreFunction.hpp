#ifndef CORE_FUNCTION
#define CORE_FUNCTION

#include "CoreIncluding.hpp"

void ClearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
struct MessageData
{
    string text;
    string time;
};

void to_json(json& j, const MessageData& m)
{
    j = json{
        {"text", m.text},
        {"time", m.time}
    };
}

void from_json(const json& j, MessageData& m)
{
    m.text = j.at("text").get<string>();
    m.time = j.at("time").get<string>();
}

tuple<int, string> HandleResponse(const string& input) 
{
    size_t spacePos = input.find(' ');

    if (spacePos == string::npos) 
    {
        throw invalid_argument("Input must contain a space separating number and text.");
    }

    int number = stoi(input.substr(0, spacePos));
    string text = input.substr(spacePos + 1);
    return {number, text};
}

#endif