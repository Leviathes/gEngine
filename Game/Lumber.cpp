//
// Created by lucas on 11/1/2021.
//
#include "Lumber.h"


namespace Lumber {



    Logger::Logger() {

        start_Time = (Time::now());
    }



    void Logger::LogToConsole(const std::string& message ) {

        double_sec timeNow = Time::now() - start_Time;

        std::cout << std::setprecision(3) << ((double)timeNow.count() +1 ) / 1000;

        std::cout  << " - " << message << std::endl;


    }

    void Logger::LogToFile(const std::string& message) {

    }

    void Logger::LogToFile(const std::string& message, const std::string& fileName) {


    }
}
