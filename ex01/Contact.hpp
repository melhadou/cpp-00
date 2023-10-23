#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;

public:
  Contact(void);
  ~Contact(void);

  void init(void);
  void printContacts(int i);
  void printContactById();
  bool valiPhoneNumber(std::string phoneNumber);
};

std::string getInput(std::string prompt);
std::string trunc(std::string str);
#endif
