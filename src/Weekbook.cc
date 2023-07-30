#include "Weekbook.hh"

const std::time_t NDR_SECONDS_IN_WEEK = 604800;
const std::time_t NDR_SECONDS_IN_DAY = 86400;
const std::time_t NDR_SECONDS_IN_MONTH = 2592000;
const std::time_t NDR_SECONDS_IN_YEAR = 946080000;

std::tm enterDate() {
	std::tm date;
	int day, month, year, hour, minute;
	std::string act_name, act_desc;
	std::cout << "Enter the day, month, year, hour and minute, "
			  << "separated by spaces:" << std::endl;
	while (std::cin >> day) {
		if (day > 0 && day < 32) {
			date.tm_mday = day;
			break;
		}
		else std::cout << "Try again.\n";
	}
	while (std::cin >> month) {
		if (month > 0 && month < 13) {
			date.tm_mon = --month;
			break;
		}
		else std::cout << "Try again.\n";
	}
	while (std::cin >> year) {
		if (year > 0 && year < 10000) {
			date.tm_year = year - 1900;
			break;
		}
		else std::cout << "Try again.\n";
	}
	while (std::cin >> hour) {
		if (hour >= 0 && hour < 24) {
			date.tm_hour = hour;
			break;
		}
		else std::cout << "Try again.\n";
	}
	while (std::cin >> minute) {
		if (minute >= 0 && minute < 60) {
			date.tm_min = minute;
			break;
		}
		else std::cout << "Try again.\n";
	}
	return date;
}

void Weekbook::sortActivities() {
	std::sort(activities_.begin(), activities_.end(),
			  [] (Activity first, Activity last) {
				  auto first_date = first.getDate();
				  auto last_date = last.getDate();
				  if (first_date.tm_year < last_date.tm_year)
					  return true;
				  if (first_date.tm_year > last_date.tm_year)
					  return false;
				  if (first_date.tm_mon < last_date.tm_mon)
					  return true;
				  if (first_date.tm_mon > last_date.tm_mon)
					  return false;
				  if (first_date.tm_mday < last_date.tm_mday)
					  return true;
				  if (first_date.tm_mday > last_date.tm_mday)
					  return false;
				  if (first_date.tm_hour < last_date.tm_hour)
					  return true;
				  if (first_date.tm_hour > last_date.tm_hour)
					  return false;
				  return first_date.tm_min < last_date.tm_min;
			  });
}

void Weekbook::addActivity(const Activity& activity) {
	activities_.push_back(activity);
	this->sortActivities();
}

void Weekbook::showActivities() {
	std::time_t current_date_seconds = std::time(nullptr);
	std::time_t period = 0;
	std::cout << "Choose the period you want to see:\n"
			  << "1. A day.\n"
			  << "2. A week.\n"
			  << "3. A month.\n"
			  << "4. A year.\n"
			  << "5. All activities.\n"
			  << "6. A custom period (specify the day and the period)."
			  << std::endl;
	int action;
	bool show_all = false;
	bool custom_period = false;
	std::tm custom_date;
	std::time_t custom_date_seconds = 0;
	std::cin >> action;
	switch (--action) {
	case 0:
		period = NDR_SECONDS_IN_DAY;
		break;
	case 1:
		period = NDR_SECONDS_IN_WEEK;
		break;
	case 2:
		period = NDR_SECONDS_IN_MONTH;
		break;
	case 3:
		period = NDR_SECONDS_IN_YEAR;
		break;
	case 4:
		show_all = true;
		break;
	case 5:
		custom_period = true;
		custom_date = enterDate();
		custom_date_seconds = std::mktime(&custom_date);
		std::cout << "Choose the period you want to see:\n"
			  << "1. A day.\n"
			  << "2. A week.\n"
			  << "3. A month.\n"
			  << "4. A year.\n"
			  << std::endl;
		std::cin >> action;
		switch (--action) {
		case 0:
			period = NDR_SECONDS_IN_DAY;
			break;
		case 1:
			period = NDR_SECONDS_IN_WEEK;
			break;
		case 2:
			period = NDR_SECONDS_IN_WEEK;
			break;
		case 3:
			period = NDR_SECONDS_IN_YEAR;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	for (auto& activity : this->activities_) {
		std::tm activity_date = activity.getDate();
		std::time_t activity_date_seconds = std::mktime(&activity_date);
		if (activity_date_seconds - current_date_seconds > period
			&& !show_all && !custom_period)
			break;
		if (custom_period == true
			&& (custom_date_seconds - activity_date_seconds) > period)
			continue;
		activity.printActivity();
	}
}
