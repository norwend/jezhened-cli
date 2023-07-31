#pragma once

#include <chrono>
#include <string>
#include <cmath>

const std::string JEZHENED_DATE_FORMAT = "%H:%M %d.%m.%Y";

class Date {
private:
	std::chrono::time_point<std::chrono::system_clock> time_point_;
	uint32_t hour_, minute_, day_, month_, year_;
	void updateDate();
public:
	uint32_t hour() { return this->hour_; }
	uint32_t minute() { return this->minute_; }
	uint32_t day() { return this->day_; }
	uint32_t month() { return this->month_; }
	uint32_t year() { return this->year_; }

	// create setters!
	void setTimePoint(const std::chrono::time_point<std::chrono::system_clock>& new_time_point);

	Date() = default;
	Date(const std::string& date_string);
	Date(std::tm date);
	Date(const Date& other) :
		time_point_(other.time_point_), hour_(other.hour_),
		minute_(other.minute_), day_(other.day_), month_(other.month_),
		year_(other.year_) {}
	~Date() = default;

	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
};


