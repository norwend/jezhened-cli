#include "Date.hh"

void Date::setTimePoint(const std::chrono::time_point<std::chrono::system_clock>& new_time_point) {
	this->time_point_ = new_time_point;
	this->updateDate();
}

void Date::updateDate() {
	using namespace std::chrono;
	year_month_day ymd { floor<days>(time_point_) };
	hh_mm_ss hms { time_point_ - floor<days>(time_point_) };
	hour_ = hms.hours().count();
	minute_ = hms.minutes().count();
	day_ = static_cast<uint32_t>(ymd.day());
	month_ = static_cast<uint32_t>(ymd.month());
	year_ = std::abs(int(ymd.year()));
}

Date::Date(const std::string& date_string) {
	date_string >> std::chrono::parse(JEZHENED_DATE_FORMAT, time_point_);
	this->updateDate();
}

Date::Date(std::tm date) {
	std::time_t since_epoch = std::mktime(&date);
	this->time_point_ = std::chrono::system_clock::from_time_t(since_epoch);
	this->updateDate();
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
