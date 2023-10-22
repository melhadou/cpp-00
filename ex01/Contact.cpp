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

// void Contact::printContactById() {
//   if (this->_firstName.empty() && this->_lastName.empty() &&
//       this->_nickname.empty() && this->_phoneNumber.empty() &&
//       this->_darkestSecret.empty()) {
//     return;
//   }
//   std::cout << GREEN << "Contact Details" << RESET << std::endl;
//   std::cout << "First Name: " << this->_firstName << std::endl;
//   std::cout << "Last Name: " << this->_lastName << std::endl;
//   std::cout << "Nickname: " << this->_nickname << std::endl;
//   std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
//   std::cout << UNDERLINE << "Darkest Secret: " << this->_darkestSecret <<
//   RESET
//             << std::endl;
// }

void Contact::printContactById() {
  if (this->_firstName.empty() && this->_lastName.empty() &&
      this->_nickname.empty() && this->_phoneNumber.empty() &&
      this->_darkestSecret.empty()) {
    std::cout << RED << "Contact not found" << RESET << std::endl;
    return;
  }

  std::cout << GREEN << "Contact Details" << RESET << std::endl;
  std::cout << std::left; // Set the alignment to left for field names
  std::cout << std::setw(15) << "First Name:" << this->_firstName << std::endl;
  std::cout << std::setw(15) << "Last Name:" << this->_lastName << std::endl;
  std::cout << std::setw(15) << "Nickname:" << this->_nickname << std::endl;
  std::cout << std::setw(15) << "Phone Number:" << this->_phoneNumber
            << std::endl;

  // Reset the alignment to the default (right) for the last line
  std::cout << std::right;
  std::cout << UNDERLINE << "Darkest Secret:" << this->_darkestSecret << RESET
            << std::endl;
}

bool Contact::valiPhoneNumber(std::string phoneNumber) {
  int phone;
  if (phoneNumber.length() != 10) {
    std::cout << RED << "Invalid Phone Number: Length should be 10" << RESET
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
