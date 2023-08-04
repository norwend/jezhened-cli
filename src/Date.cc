#include "Date.hh"

std::string Date::toString() {
	return std::format(JEZHENED_OUTPUT_DATE_FORMAT, time_point_);
}

void Date::setTimePoint(const std::chrono::time_point<std::chrono::system_clock>& new_time_point) {
	this->time_point_ = new_time_point;
}

uint32_t Date::hour() {
	using namespace std::chrono;
	return hh_mm_ss { time_point_ - floor<days>(time_point_) }.hours().count();
}
uint32_t Date::minute() {
	using namespace std::chrono;
	return hh_mm_ss { time_point_ - floor<days>(time_point_) }.minutes().count();
}
uint32_t Date::day() {
	using namespace std::chrono;
	return static_cast<uint32_t>(year_month_day{floor<days>(time_point_)}.day());
}
uint32_t Date::month() {
	using namespace std::chrono;
	return static_cast<uint32_t>(year_month_day{floor<days>(time_point_)}.month());
}
uint32_t Date::year() {
	using namespace std::chrono;
	return std::abs(int(year_month_day{floor<days>(time_point_)}.year()));
}

Date::Date(const std::string& date_string) {
	// date_string >> std::chrono::parse(JEZHENED_DATE_FORMAT, time_point_); --- C++20 FULL SUPPORT WAITING ROOM ---
	std::tm tm = {};
	std::stringstream ss { date_string };
	ss >> std::get_time(&tm, JEZHENED_DATE_FORMAT.c_str());
	this->time_point_ = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

Date::Date(std::tm date) {
	std::time_t since_epoch = std::mktime(&date);
	this->time_point_ = std::chrono::system_clock::from_time_t(since_epoch);
}

bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.time_point_ < rhs.time_point_;
}

bool operator>(const Date& lhs, const Date& rhs) {
	return rhs < lhs;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.time_point_ == rhs.time_point_;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}
