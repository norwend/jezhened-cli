#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

void ndrprint(std::string str) {
	std::cout << str << std::endl;
}

enum UserInput {
	ShowWeekActivities,
	AddActivity,
	RemoveActivity,
	ShowMonthActivities,
};

class Activity {
private:
	std::tm date_;
	std::string name_;
	std::string description_;
	int priority_;
	bool state_;
public:
	std::tm getDate();
	std::string getName();
	std::string getDescription();
	int getPriority();
	bool getState();

	void setDate(const std::tm& new_date);
	void setName(const std::string& new_name);
	void setDescription(const std::string& new_description);
	void setPriority(int new_priority);
	void setState(bool new_state);
	
	void printActivity();
	Activity(const std::string& name,
			 const std::string& description,
			 const std::tm& date);
	~Activity() = default;
};

Activity::Activity(const std::string& name,
				   const std::string& description,
				   const std::tm& date)
	: name_(name), description_(description), date_(date) {
	
}

std::tm Activity::getDate() {
	return this->date_;
}

std::string Activity::getName() {
	return this->name_;
}

std::string Activity::getDescription() {
	return this->description_;
}

int Activity::getPriority() {
	return this->priority_;
}

bool Activity::getState() {
	return this->state_;
}

void Activity::setDate(const std::tm& new_date) {
	this->date_ = new_date;
}

void Activity::setName(const std::string& new_name) {
	this->name_ = new_name;
}

void Activity::setDescription(const std::string& new_description) {
	this->description_ = new_description;
}

void Activity::setPriority(int new_priority) {
	this->priority_ = new_priority;
}

void Activity::setState(bool new_state) {
	this->state_ = new_state;
}

void Activity::printActivity() {
	char date_string[std::size("dd.mm.yyyy hh:mm")];
	std::tm activity_date = this->getDate();
	size_t date_get_result = std::strftime(date_string,
										   std::size(date_string),
										   "%d.%m.%Y %R",
										   &activity_date);
	// "%R" is just an abbreviation for "%H:%M"
	if (date_get_result == 0) {
		ndrprint("Activity get failed");
	}
	std::cout << "Name: " << this->name_
			  << "\nDate: " << date_string
			  << "\nDescription: " << this->description_ << std::endl;
}

class Weekbook {
private:
	std::vector<Activity> activities_;
	void sortActivities();
public:
	void addActivity();
// 	void editActivity();
// 	void removeActivity();
	void showWeekActivities();
// 	void showMonthActivities();
// 	void showYearActivities();
//  void showAllActivities();
};

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

void Weekbook::addActivity() {
	std::tm date{};
	int day, month, year, hour, minute;
	std::string act_name, act_desc;
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
	ndrprint("Enter the activity name: ");
	std::cin >> act_name;
	ndrprint("Enter the activity description: ");
	std::cin >> act_desc;
	activities_.push_back(Activity(act_name, act_desc, date));
	this->sortActivities();
}

void Weekbook::showWeekActivities() {
	std::time_t current_time = std::time(nullptr);
	const std::time_t MILLIS_IN_WEEK = 604800000;
	for (auto& activity : this->activities_) {
		std::tm activity_date = activity.getDate();
		std::time_t activity_time = std::mktime(&activity_date);
		if (std::abs(activity_time - current_time) > MILLIS_IN_WEEK)
			break;
		activity.printActivity();
	}
}

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
			ndrprint("Enter the day, month, year, hour and minute, "
					 "separated by spaces:");
			weekbook->addActivity();
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
