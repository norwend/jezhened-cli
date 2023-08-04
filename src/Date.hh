#pragma once

#include <chrono>
#include <format>
#include <string>
#include <cmath>

constexpr std::string JEZHENED_DATE_FORMAT = "%H:%M %d.%m.%Y";
constexpr char JEZHENED_OUTPUT_DATE_FORMAT[] = "{:%H:%M %d.%m.%Y}";

class Date {
private:
	std::chrono::time_point<std::chrono::system_clock> time_point_;
public:
	uint32_t hour();
	uint32_t minute();
	uint32_t day();
	uint32_t month();
	uint32_t year();

	std::chrono::time_point<std::chrono::system_clock> getTimePoint() {
		return this->time_point_;
	}
	void setTimePoint(const std::chrono::time_point<std::chrono::system_clock>& new_time_point);

	std::string toString();

	Date() = default;
	Date(const std::string& date_string);
	Date(std::tm date);
	~Date() = default;

	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
};


