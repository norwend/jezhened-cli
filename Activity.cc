#include "Activity.hh"

Activity::Activity(const std::string& name,
				   const std::string& description,
				   const std::tm& date)
	: name_(name), description_(description), date_(date) { }

std::tm Activity::getDate() {
	return this->date_;
}

std::string Activity::getName() {
	return this->name_;
}

std::string Activity::getDescription() {
	return this->description_;
}

int Activity::getPriority() {
	return this->priority_;
}

bool Activity::getState() {
	return this->state_;
}

void Activity::setDate(const std::tm& new_date) {
	this->date_ = new_date;
}

void Activity::setName(const std::string& new_name) {
	this->name_ = new_name;
}

void Activity::setDescription(const std::string& new_description) {
	this->description_ = new_description;
}

void Activity::setPriority(int new_priority) {
	this->priority_ = new_priority;
}

void Activity::setState(bool new_state) {
	this->state_ = new_state;
}

void Activity::printActivity() {
	char date_string[std::size("dd.mm.yyyy hh:mm")];
	std::tm activity_date = this->getDate();
	size_t date_get_result = std::strftime(date_string,
										   std::size(date_string),
										   "%d.%m.%Y %R",
										   &activity_date);
	// "%R" is just an abbreviation for "%H:%M"
	if (date_get_result == 0) {
		std::cout << "Activity get failed" << std::endl;
	}
	std::cout << "Name: " << this->name_
			  << "\nDate: " << date_string
			  << "\nDescription: " << this->description_ << std::endl;
}
