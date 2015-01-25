/*
* sys.h
*
* This is a communication system used to establish connection between "account."
* In this class, cmd stands for the username and the pointer to its corresponding account class. para stands for the pair of username and password.
* This class controls the permission that the player can access by adding or removing the account from "para" list. For more information, see the definition of enter(string, string).
*
*
*  Created on: Mar 25, 2014
*      Author: Anoxic
*/

#pragma once

#include "menu.h"

class sys: public menu {
	/*
	 Times of failure limit to prompt reset or question
	 Set to 0 to disable such function
	*/
	int reset, question;
	void init() {}
protected:
	/* The suffix of all the mail addresses under this system, "@" included */
	std::string mail_address;
public:
	/* Constructors */
	sys(menu* par, const std::string& title): menu(par, title, true), reset(0), question(0), mail_address("@example.com") {
		init();
	}

	/* Mail address adjustment */
	std::string get_mail_address() const {
		return mail_address;
	}
	void set_mail_address(const std::string& str) {
		mail_address = str;
	}

	/*
	 This method overwrites "menu"'s
	 Normally this method will ONLY be called through menu::enter(), so it does not contain back or help command.
	*/
	menu* enter(const std::string&, const std::string&);
};

