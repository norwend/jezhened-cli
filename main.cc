#include <iostream>
#include <chrono>
#include <string>

enum UserInput {
	ShowWeekActivities,
	AddActivity,
	RemoveActivity,
	ShowMonthActivities,
};

class Activity {
private:
	std::chrono::time_point<std::chrono::system_clock> time_;
	std::string name_;
	std::string description_;
public:
	void printActivity();
};

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

int askAction() {
	int action;
	std::cin >> action;
	return action;
}

int main () {
	std::cout << "Hello, world\n";
	Weekbook* weekbook = new Weekbook;
	while (true) {
		int action = askAction();
		switch (action) {
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
