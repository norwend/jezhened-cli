#include <iostream>

#include "Activity.hh"
#include "Weekbook.hh"

enum UserInput {
	ShowActivities,
	AddActivity,
	RemoveActivity,
	Quit,
};

int main () {
	Weekbook* weekbook = new Weekbook;
	while (true) {
		std::cout << "Choose action...\n"
				  << "1. Show activities.\n"
				  << "2. Add an activity.\n"
				  << "3. Edit an activity.\n"
				  << "4. Quit.\n"
				  << "> ";
		int action;
		std::cin >> action;
		std::string act_name, act_desc;
		switch (--action) {
		case UserInput::ShowActivities:
			weekbook->showActivities();
			continue;
		case UserInput::AddActivity:
			std::cout << "Enter the activity name:\n"
					  << "> ";
			std::cin >> act_name;
			std::cout << "Enter the activity description:\n"
					  << "> ";
			std::cin >> act_desc;
			weekbook->addActivity(Activity(act_name, act_desc, enterDate()));
			continue;
		case UserInput::RemoveActivity:
			// weekbook->removeActivity();
			continue;
		case UserInput::Quit:
			break;
		default:
			continue;
		}
		break;
	}
	return 0;
}
