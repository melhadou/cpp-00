#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define UNDERLINE "\033[4;37m"

class PhoneBook {
private:
  int idx; // value = 0
  Contact contacts[8];

public:
  PhoneBook(void);
  void addContact(void);
  void printContacts(void);
  void searchForContact(void);
  int validContactId();
};

#endif
