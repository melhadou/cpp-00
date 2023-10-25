#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void Contact::init() {
  std::cout << "Add New Contact Details" << std::endl;
  this->_firstName = getInput("First Name");
  this->_lastName = getInput("Last Name");
  this->_nickname = getInput("Nickname");
  std::string phone = getInput("Phone Number");
  while (!valiPhoneNumber(phone)) {
    phone = getInput("Phone Number");
  }
  this->_phoneNumber = phone;
  this->_darkestSecret = getInput("Darkest Secret");
  return;
}

void Contact::printContacts(int i) {
  std::cout << std::setw(10) << i << "|" << trunc(this->_firstName) << "|"
            << trunc(this->_lastName) << "|" << trunc(this->_nickname) << "|"
            << std::endl;
  return;
}

void Contact::printContactById() {
  if (this->_firstName.empty() && this->_lastName.empty() &&
      this->_nickname.empty() && this->_phoneNumber.empty() &&
      this->_darkestSecret.empty()) {
    std::cout << RED << "Contact not found" << RESET << std::endl;
    return;
  }

  std::cout << "\t" << GREEN << "Contact Details" << RESET << std::endl;
  std::cout << std::left;
  printKeyVal("First Name", this->_firstName);
  printKeyVal("Last Name", this->_lastName);
  printKeyVal("Nickname Name", this->_nickname);
  printKeyVal("Phone Number", this->_phoneNumber);
  printKeyVal("Darkest Secret", this->_darkestSecret);
  std::cout << std::right;
}

bool Contact::valiPhoneNumber(std::string phoneNumber) {
  long phone = 0;
  if (phoneNumber.length() <= 9) {
    std::cout << RED << "Invalid Phone Number: length > 9" << RESET
              << std::endl;
    return (false);
  }
  // vlaidate if phone is a number
  std::stringstream ss;
  ss << phoneNumber;
  if (!(ss >> phone)) {
    std::cout << RED << "Invalid Phone Number" << RESET << std::endl;
    return (false);
  }
  return true;
}

void printKeyVal(std::string key, std::string value) {
  std::cout << "\t" << std::setw(15) << key << std::setw(5) << ":" << value
            << std::endl;
}
