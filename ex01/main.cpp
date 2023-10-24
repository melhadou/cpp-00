#include "PhoneBook.hpp"

int main(void) {
  std::string input;
  std::string id;

  PhoneBook PhoneBook;
  std::cout << UNDERLINE << "Welcome To The Old PhoneBook" << RESET
            << std::endl;
  while (true) {
    std::cout << "PhoneBook>>: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
      break;
    else if (!input.compare("ADD")) {
      PhoneBook.addContact();
    } else if (!input.compare("SEARCH")) {
      PhoneBook.searchForContact();
    } else if (!input.compare("EXIT")) {
      exit(EXIT_SUCCESS);
    } else {
      std::cout << RED << "Invalid Command" << RESET << std::endl;
      std::cout << GREEN << "Available Commands: ADD, SEARCH, EXIT" << RESET
                << std::endl;
    }
  }
  return 0;
}
