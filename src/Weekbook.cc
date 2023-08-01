#include "Weekbook.hh"

Date enterDate() {
	std::cin.clear();
	std::cin.sync();
	std::cout << "Enter the date in format HH:MM DD.MM.YYYY: \n";
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

void Weekbook::showActivities() {
	using namespace std::chrono;
	
	auto current_time = system_clock::now();
	std::cout << "Choose the period you want to see:\n"
			  << "1. A day.\n"
			  << "2. A week.\n"
			  << "3. A month.\n"
			  << "4. A year.\n"
			  << "5. All activities.\n"
			  << "6. A custom period (specify the day and the period)."
			  << std::endl;
	std::chrono::minutes period;
	int action;
	bool show_all = false;
	bool custom_period = false;
	Date custom_date {};
	std::cin >> action;
	switch (--action) {
	case 0:
		period = duration_cast<minutes>(days(1));
		break;
	case 1:
		period = duration_cast<minutes>(days(7));
		break;
	case 2:
		period = duration_cast<minutes>(days(30));
		break;
	case 3:
		period = duration_cast<minutes>(days(365));
		break;
	case 4:
		show_all = true;
		break;
	case 5:
		custom_period = true;
		custom_date = enterDate();
		std::cout << "Choose the period you want to see:\n"
			  << "1. A day.\n"
			  << "2. A week.\n"
			  << "3. A month.\n"
			  << "4. A year."
			  << std::endl;
		std::cin >> action;
		switch (--action) {
		case 0:
			period = duration_cast<minutes>(days(1));
			break;
		case 1:
			period = duration_cast<minutes>(days(7));
			break;
		case 2:
			period = duration_cast<minutes>(days(30));
			break;
		case 3:
			period = duration_cast<minutes>(days(365));
			break;
		default:
			break;
		}
		break;
	default:
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
