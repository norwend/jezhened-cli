#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

#include "Date.hh"

class Activity {
private:
	std::string name_;
	std::string description_;
	Date date_;
public:
	Date getDate();
	std::string getName();
	std::string getDescription();

	void setDate(const Date& new_date);
	void setName(const std::string& new_name);
	void setDescription(const std::string& new_description);
	
	void printActivity();
	Activity(const std::string& name,
			 const std::string& description,
			 const Date& date);
	~Activity() = default;
};
