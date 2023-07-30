#pragma once

#include <chrono>
#include <string>

class Date {
private:
	std::chrono::time_point<std::chrono::system_clock> time_point_;
	std::chrono::year year_;
	std::chrono::month month_;
	std::chrono::day day_;
	std::chrono::hh_mm_ss time_;
public:
	std::string getDate();
};
