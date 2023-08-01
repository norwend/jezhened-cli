#include <iostream>

#include "Activity.hh"
#include "Weekbook.hh"

enum UserInput {
	ShowActivities,
	AddActivity,
	RemoveActivity,
	ShowMonthActivities,
};

int main () {
	Weekbook* weekbook = new Weekbook;
	while (true) {
		std::cout << "Choose action...\n"
				  << "1. Show activities.\n"
				  << "2. Add an activity.\n";
		int action;
		std::cin >> action;
		std::string act_name, act_desc;
		switch (--action) {
		case UserInput::ShowActivities:
			weekbook->showActivities();
			break;
		case UserInput::AddActivity:
			std::cout << "Enter the activity name: " << std::endl;
			std::cin >> act_name;
			std::cout << "Enter the activity description: " << std::endl;
			std::cin >> act_desc;
			weekbook->addActivity(Activity(act_name, act_desc, enterDate()));
			break;
		case UserInput::RemoveActivity:
			// weekbook->removeActivity();
			break;
		default:
			break;
		}
	}
	return 0;
}
