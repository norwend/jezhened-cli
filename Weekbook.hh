#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

#include "Activity.hh"

class Weekbook {
private:
	std::vector<Activity> activities_; // TODO: use pointers instead of copies (preferrably smart pointers)
	void sortActivities();
public:
	void addActivity(const Activity& activity);
// 	void editActivity();
// 	void removeActivity();
	void showWeekActivities();
// 	void showMonthActivities();
// 	void showYearActivities();
//  void showAllActivities();
};
