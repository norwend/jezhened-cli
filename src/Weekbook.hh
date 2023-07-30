#pragma once

#include <vector>
#include <algorithm>

#include "Activity.hh"

class Weekbook {
private:
	std::vector<Activity> activities_; // TODO: use pointers instead of copies (preferrably smart pointers)
	void sortActivities();
public:
	void addActivity(const Activity& activity);
// 	void editActivity();
// 	void removeActivity();
	void showActivities();
};

std::tm enterDate();
