/*
 account.h
 This class stands for a user account.
 The account can be used to send / receive messages.
 The variable of para in this class contains the pair of reset
 questions if there are any.

 Process of attempting to log in into an account but failed:
 1. Check if "reset_limit" is > 0 (reset enabled)
 2. (If enabled) Increment "fail" by 1 and test if it is >= "reset_lim" (reset triggered)
 3. (If triggered) Call this->reset()
 4.1 If "reset_password" is empty, lock the account right away
 4.2 Else, test if "para" of "account" is empty (have questions to answered before reset?)
 4.2.1 (If so) Iterate to prompt user to answer all of the questions
	Any failure to provide correct key will terminate the reset process immediately
 5. Reset the password to "reset_password"
 6. Reset reset_limit

 *  Created on: Mar 24, 2014
 *      Author: Ano
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <map>

#include "dialog.h"
#include "menu.h"
#include "inbox.h"
#include "outbox.h"
#include "sys.h"

class account: public menu {
	/* The times of failure to log in; trigger reset or question */
	int fail;
	/*
	 Times of failure required to trigger password reset
	 Set to 0 to disable such function
	 If wish to prompt questions, they should be stored in "para"
	 */
	int reset_lim;
	/*
	 Default value: "password"
	 The password that will replace the current password after resetting
	 If this string is empty, this account will place itself in lock status by :
		1. modifying "desc" to abortion::ACCOUNT_ACCESS_DENIED_ERROR_LOCKED
		2. 
	 However, the user still has to manually add it to "sys" class
	 To remove "lock" status, set reset_lim to 0 (or larger for another possible reset_lim)
	 */
	std::string reset_password;
	/* The name of the user */
	std::string user;
	/*
	 The pointer(s) to inbox and outbox of this user
	 They have their "cmd" as their mails collection
	 In "cmd", the first element refers to its index, and the second element points to the mail
	 See "mailbox.h" for more information
	 */
	menu *in, *out;

	/* Only contains "submit", one-use */
	void act(const std::string&, const std::string&);
	menu* back();
	void init();
	/*
	 Reset password
	 @Return: 1 if succeeds 
			  0 if this account has been locked
			  -1 if fails
	 */
	int reset();
protected:
	/* The email address of the user */
	std::string address;
public:
	account(menu* par, const std::string& title, const std::string& name):
		menu(par, title), fail(0), reset_lim(0), reset_password("password"), user(name), in(new inbox(this)), out(new outbox(this)) {
		init();
	}
	~account() {
		delete in;
		delete out;
	}

	void set_reset_lim(int i) {
		// Valid input
		if (i >= 0) {
			if (this->reset_lim == 0) {
				// Clear desc and remove "lock" state
				this->desc = "";
			}
			this->reset_lim = i;
		}
	}
	const std::string get_reset_password() const {
		return this->reset_password;
	}
	void set_reset_password(const std::string str) {
		this->reset_password = str;
	}

	/* Utility function to fetch the suffix of the mail account */
	std::string get_address_suffix() {
		if (address == dialog::info::ADDRESS_UNDEFINED)
			// The parent of this is not a legal system
			return address;
		else
			return ((sys*)this->parent)->get_mail_address();
	}

	/* Attempt to log in */
	void attempt();
	/* Automatically refresh both mailboxes */
	void entered();
	/*
	 Send a letter to others; auto-format
	 Two accounts must be under the same system to send letters
	 */
	void send(const std::string& to, const std::string& content);
	/*
	 Receive a letter from others; auto-format
	 The 
	 letter will be automatically labeled as "new"
	 Account "from" and this account do not have to be under the same system
	 */
	void receive(const std::string& from, const std::string& content);
	/* Change the username of current user */
	void change_name(const std::string&);
};

#endif /* ACCOUNT_H_ */
