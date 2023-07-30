#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Activity {
private:
	std::string name_;
	std::string description_;
	std::tm date_;
public:
	std::tm getDate();
	std::string getName();
	std::string getDescription();

	void setDate(const std::tm& new_date);
	void setName(const std::string& new_name);
	void setDescription(const std::string& new_description);
	
	void printActivity();
	Activity(const std::string& name,
			 const std::string& description,
			 const std::tm& date);
	~Activity() = default;
};
