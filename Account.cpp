#include "stdafx.h"
#include "Account.h"
#include <iostream>
#include <iomanip>

using namespace std;


Account::Account()							// default constructor
{
	accountID = getNextAccountNumber();
	accountHolder = "no name";
	balance = 0.0;
}

Account::Account(string name, double amount)	// constructor with two parameters
{
	accountID = getNextAccountNumber();			//get next account#
	accountHolder = name;
	balance = amount;
}

int		Account::getAccountID()		const		// ACCESSOR member functions
{
	return accountID;
}

string	Account::getAccountHolder()	const		// return name of account holder
{
	return accountHolder;
}

double	Account::getBalance()		const		// return account balance
{
	return balance;
}

void	Account::setAccountHolder(string name)	// MUTATOR member functions
{
	accountHolder = name;
}

void	Account::setBalance(double amt)			// assign amount to balance
{
	amt = amt + balance;
	static_cast<double>(balance) = amt;
}

void	Account::depositAmount(double amt)		// add amount to balance
{
	if (amt > 0.0)
		Account::setBalance(amt);
}
void	Account::withdrawAmount(double amt)		// subtract absolute value of amount from balance
{												// HELPER member functions
	amt = fabs(amt);
	Account::setBalance(-amt);

}
void	Account::displayAccountInfo()	const	// display account information
{
	cout << fixed << setprecision(2);
	cout << getAccountID() << " \t$" << right << setw(12) << getBalance() << left << '\t' << getAccountHolder() << endl;
}
int		Account::getNextAccountNumber()	const	// get next account# (return pre-incremented accountNumber)
										// private DATA members
{
	return ++accountNumber;}