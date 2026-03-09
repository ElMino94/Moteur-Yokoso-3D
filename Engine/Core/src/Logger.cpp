#include "Logger.h"

#include <iostream>

void Logger::Log(const std::string& message) {

	std::cout << "[Info] " << message << std::endl;

}

void Logger::Warn(const std::string& message) {

	std::cout << "[Warning ]" << message << std::endl;

}

void Logger::Error(const std::string& message) {

	std::cout << "[Error] " << message << std::endl;

}