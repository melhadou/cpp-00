#include "Account.hpp"
#include <ctime>
#include <iostream>

// initialtize static members variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void printTimeStump(void) {
  time_t currentTime;
  char buffer[80];
  struct tm *localTime;

  time(&currentTime);
  localTime = localtime(&currentTime);

  strftime(buffer, 80, "[%Y%m%d_%H%M%S]", localTime);
  std::cout << buffer << " ";
}

Account::Account(int initial_deposit) {
  //
  // initialize variables
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  this->_accountIndex = this->_nbAccounts;
  this->_nbAccounts += 1;
  this->_amount = initial_deposit;
  this->_totalAmount += this->_amount;
  printTimeStump();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account(void) {
  printTimeStump();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  printTimeStump();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
  printTimeStump();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  printTimeStump();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";
  if (withdrawal > this->_amount) {
    std::cout << "refused" << std::endl;
    return false;
  }
  this->_amount -= withdrawal;
  this->_nbWithdrawals += 1;
  std::cout << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  _totalAmount -= withdrawal; // update total amount
  _totalNbWithdrawals += 1;   // update total number of withdrawals
  return true;
}

void Account::makeDeposit(int deposit) {
  printTimeStump();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:" << deposit;
  if (deposit < 0) {
    return;
  }
  this->_amount += deposit;
  this->_nbDeposits += 1;
  std::cout << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
  _totalAmount += deposit;               // update total amount
  _totalNbDeposits += this->_nbDeposits; // update total number of deposits
}

int Account::checkAmount(void) const { return _amount; }
