#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

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
public:
	std::tm getDate();
	std::string getName();
	std::string getDescription();
	int getPriority();

	std::string getFormattedDate(std::string format);

	void setDate(const std::tm& new_date);
	void setName(const std::string& new_name);
	void setDescription(const std::string& new_description);
	void setPriority(int new_priority);
	
	void printActivity();
	Activity(const std::string& name,
			 const std::string& description,
			 const std::tm& date);
	~Activity();
};

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

class Weekbook {
private:
	std::vector<Activity> activities_;
public:
	void addActivity();
	void editActivity();
	void removeActivity();
	void showWeekActivities();
	void showMonthActivities();
	void showYearActivities();
};

void ndrprint(std::string str) {
	std::cout << str << std::endl;
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
	
}

int main () {
	std::cout << "Hello, world\n";
	Weekbook* weekbook = new Weekbook;
	while (true) {
		int action;
		std::cin >> action;
		switch (--action) {
		case UserInput::ShowWeekActivities:
			weekbook->showWeekActivities();
			break;
		case UserInput::AddActivity:
			weekbook->addActivity();
			break;
		case UserInput::RemoveActivity:
			weekbook->removeActivity();
			break;
		case UserInput::ShowMonthActivities:
			weekbook->showMonthActivities();
			break;
		default:
			break;
		}
	}
	return 0;
}
