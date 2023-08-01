#include "Activity.hh"

Activity::Activity(const std::string& name,
				   const std::string& description,
				   const Date& date)
	: name_(name), description_(description), date_(date) { }

Date Activity::getDate() {
	return this->date_;
}

std::string Activity::getName() {
	return this->name_;
}

std::string Activity::getDescription() {
	return this->description_;
}

void Activity::setDate(const Date& new_date) {
	this->date_ = new_date;
}

void Activity::setName(const std::string& new_name) {
	this->name_ = new_name;
}

void Activity::setDescription(const std::string& new_description) {
	this->description_ = new_description;
}

void Activity::printActivity() {
	std::cout << "Name: " << this->name_
			  << "\nDate: " << this->date_.toString()
			  << "\nDescription: " << this->description_ << std::endl;
}
