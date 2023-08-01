#include "Weekbook.hh"

Date enterDate() {
	std::cin.clear();
	std::cin.sync();
	std::cout << "Enter the date in format HH:MM DD.MM.YYYY: \n"
			  << "> ";
	std::string date_string;
	std::getline(std::cin, date_string);
	return Date(date_string);
}

void Weekbook::sortActivities() {
	std::sort(activities_.begin(), activities_.end(),
			  [] (Activity first, Activity last) {
				  return first.getDate() < last.getDate();
			  });
}

void Weekbook::addActivity(const Activity& activity) {
	activities_.push_back(activity);
	this->sortActivities();
}

std::chrono::minutes periodChooser() {
	using namespace std::chrono;
	
	std::cout << "Choose the period you want to see:\n"
			  << "1. A day.\n"
			  << "2. A week.\n"
			  << "3. A month.\n"
			  << "4. A year.\n"
			  << "> ";
	int action;
	std::cin >> action;
	switch (--action) {
	case 0:
		return duration_cast<minutes>(days(1));
		break;
	case 1:
		return duration_cast<minutes>(days(7));
		break;
	case 2:
		return duration_cast<minutes>(days(30));
		break;
	case 3:
		return duration_cast<minutes>(days(365));
		break;
	default:
		return duration_cast<minutes>(days(-1));
	}
}

void Weekbook::showActivities() {
	using namespace std::chrono;
	
	auto current_time = system_clock::now();
	std::cout << "Which activities you want to see? (enter a number)\n"
			  << "1. All activities\n"
			  << "2. Within a specific period\n"
			  << "3. From a specific date and within a specific period\n"
			  << "> ";
	int action;
	bool show_all = false;
	bool custom_period = false;
	Date custom_date {};
	std::chrono::minutes period;
	std::cin >> action;
	switch (--action) {
	case 0:
		show_all = true;
		break;
	case 1:
		period = periodChooser();
		break;
	case 2:
		custom_period = true;
		custom_date = enterDate();
		period = periodChooser();
		break;
	default:
		period = duration_cast<minutes>(days(-1));
		break;
	}
	for (auto& activity : this->activities_) {
		auto activity_duration =
			duration_cast<minutes>(activity.getDate().getTimePoint()
								   - current_time);
		if ((activity_duration > period || activity_duration.count() < 0)
			&& !show_all && !custom_period)
			break;
		if (custom_period == true) {
			auto custom_duration =
				duration_cast<minutes>(activity.getDate().getTimePoint()
									   - custom_date.getTimePoint());
			if (custom_duration > period || custom_duration.count() < 0)
				continue;
		}
		activity.printActivity();
	}
}
