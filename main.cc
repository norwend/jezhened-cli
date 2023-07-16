#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

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

	std::string getFormattedDate(std::string format);

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

class Weekbook {
private:
	std::vector<Activity> activities_;
	void sortActivities();
public:
	void addActivity();
// 	void editActivity();
// 	void removeActivity();
// 	void showWeekActivities();
// 	void showMonthActivities();
// 	void showYearActivities();
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
	int year;
	std::string act_name;
	std::string act_desc;
	std::cin >> date.tm_mday;
	std::cin >> date.tm_mon;
	std::cin >> year;
	date.tm_year = year - 1900;
	std::cin >> date.tm_hour;
	std::cin >> date.tm_min;
	std::mktime(&date);
	ndrprint("Enter the activity name: ");
	std::cin >> act_name;
	ndrprint("Enter the activity description: ");
	std::cin >> act_desc;
	activities_.push_back(Activity(act_name, act_desc, date));
	this->sortActivities();
}

int main () {
	std::cout << "Hello, world\n";
	Weekbook* weekbook = new Weekbook;
	while (true) {
		int action;
		std::cin >> action;
		switch (--action) {
		case UserInput::ShowWeekActivities:
			// weekbook->showWeekActivities();
			break;
		case UserInput::AddActivity:
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
