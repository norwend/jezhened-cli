#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Activity {
private:
	std::string name_;
	std::string description_;
	std::tm date_;
	int priority_ = 0;
	bool state_ = false;
public:
	std::tm getDate();
	std::string getName();
	std::string getDescription();
	int getPriority();
	bool getState();

	void setDate(const std::tm& new_date);
	void setName(const std::string& new_name);
	void setDescription(const std::string& new_description);
	void setPriority(int new_priority);
	void setState(bool new_state);
	
	void printActivity();
	Activity(const std::string& name,
			 const std::string& description,
			 const std::tm& date);
	~Activity() = default;
};
