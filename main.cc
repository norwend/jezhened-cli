#include <iostream>

#include "Activity.hh"
#include "Weekbook.hh"

enum UserInput {
	ShowWeekActivities,
	AddActivity,
	RemoveActivity,
	ShowMonthActivities,
};

int main () {
	std::cout << "Hello, world\n";
	Weekbook* weekbook = new Weekbook;
	while (true) {
		std::cout << "Choose action...\n"
				  << "1. Show week activities.\n"
				  << "2. Add an activity.\n";
		int action;
		std::cin >> action;
		switch (--action) {
		case UserInput::ShowWeekActivities:
			weekbook->showWeekActivities();
			break;
		case UserInput::AddActivity:
			{
				std::tm date{};
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
						date.tm_mon = month;
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
				std::cout << "Enter the activity name: " << std::endl;
				std::cin >> act_name;
				std::cout << "Enter the activity description: " << std::endl;
				std::cin >> act_desc;
				weekbook->addActivity(Activity(act_name, act_desc, date));
			}
			break;
		case UserInput::RemoveActivity:
			// weekbook->removeActivity();
			break;
		case UserInput::ShowMonthActivities:
			// weekbook->showMonthActivities();
			break;
		default:
			break;
		}
	}
	return 0;
}
