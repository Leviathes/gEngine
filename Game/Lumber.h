//
// Created by lucas on 11/1/2021.
//

#ifndef LUMBERLOGS_LUMBER_H
#define LUMBERLOGS_LUMBER_H
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>


namespace Lumber {
    using Time = std::chrono::steady_clock;
    using ms = std::chrono::milliseconds;
    using double_sec = std::chrono::duration<double, std::milli>;
    using double_time_point = std::chrono::time_point<Time, double_sec>;


class Logger {

    double_time_point start_Time;

public:
    Logger();
    void LogToConsole(const std::string& message);
    void LogToFile(const std::string& message);
    void LogToFile(const std::string& message, const std::string& fileName);
};



}




#endif //LUMBERLOGS_LUMBER_H
