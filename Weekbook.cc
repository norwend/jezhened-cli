#include "Weekbook.hh"

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
