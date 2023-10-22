#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

void PhoneBook::addContact() {
  int idContact = this->idx % 8;
  std::cout << this->idx << " " << idContact << std::endl;
  this->contacts[idContact % 8].init();
  this->idx++;
  std::cout << "Contact Saved Successfully" << std::endl;
  return;
}

void PhoneBook::searchForContact() {
  if (!this->idx) {
    std::cout << RED << "No Contacts Found" << RESET << std::endl;
    return;
  }
  this->printContacts();
  int input = this->validContactId();
  this->contacts[input - 1].printContactById();
  return;
}

void PhoneBook::printContacts() {
  int nbContact = this->idx;
  if (nbContact > 8)
    nbContact = 8;
  std::cout << UNDERLINE << std::endl;
  std::cout << trunc("Index") << "|" << trunc("First Name") << "|"
            << trunc("Last Name") << "|" << trunc("Nickname") << "|"
            << std::endl;
  for (int i = 0; i < nbContact; i++) {
    this->contacts[i].printContacts(i + 1);
  }
  std::cout << RESET << std::endl;
  return;
}

int PhoneBook::validContactId() {
  std::string input;
  int id = 0;
  bool validContactId = false;
  do {
    std::cout << GREEN << "Enter Contact Index: " << RESET << std::endl;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    ss >> id;
    // handle Ctrl+D
    if (id > 0 && id <= 8) {
      validContactId = true;
    } else {
      std::cout << RED << "Invalid Contact index" << RESET << std::endl;
    }
    if (std::cin.eof())
      exit(EXIT_FAILURE);
  } while (!validContactId);
  return (id);
}

/* ------ Genral Funcs ------- */
std::string trunc(std::string str) {
  if (str.length() > 10)
    str = str.substr(0, 9) + ".";
  std::cout << std::setw(10);
  return str;
}

std::string getInput(std::string prompt) {
  std::string input;
  std::cout << "\t" << prompt << ": ";
  std::getline(std::cin, input);
  if (std::cin.eof())
    exit(EXIT_FAILURE);
  if (input.empty()) {
    std::cout << RED << prompt << " cannot be empty" << RESET << std::endl;
    return getInput(prompt);
  }
  return input;
}
