/*
 * account.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Ano
 */

#include "stdafx.h"

#include <string>
#include <iostream>

#include "account.h"
#include "dialog.h"
#include "mail.h"

using namespace dialog;

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void account::act(const std::string& name, const std::string& para) {
	if (name == "submit") {
		menu* sub = this->find_cmd("submit")->second;
		prompt_info(dialog::info::TASK_SUBMISSION_HEADER_COMPLEX);
		// Iterate to check each piece of information
		for (int i = 1; i != 11; ++i) {
			prompt_info(dialog::info::TASK_SUBMISSION_PIECE + std::to_string(i));
			std::string str = prompt_input();
			if (str != dialog::story::PASSPHRASE[i]) {
				// Varification failed
				prompt_abortion(dialog::abortion::TASK_SUBMISSION_INCORRECT);
				// Immediately terminate this function
				return;
			}
		}
		// Passphrase check passed
		prompt_info(dialog::info::TASK_SUBMISSION_CORRECT);
		// Remove the command to signal
		this->remove_cmd("submit");
	}
}

menu* account::back() {
	// Double back(); first back to system class, then back to main menu
	return this->parent->back();
}

void account::init() {
	// Initialze "address"
	try {
		// If the parent of this account is a legal system, return 
		address = user + ((sys*) this->parent)->get_mail_address();
	} catch (std::bad_cast& e) {
		address = dialog::info::ADDRESS_UNDEFINED;
	}
	this->info = dialog::info::ACCOUNT_HEADER + user;
	this->add_cmd("inbox", in);
	this->add_cmd("outbox", out);
}

int account::reset() {
	// Test whether this account needs to be locked right away
	if (reset_password == "") {
		// Lock this account by removing username/password pair
		this->parent->remove_para(this->caption);
		// Change its desc
		this->desc = abortion::ACCOUNT_ACCESS_DENIED_ERROR_LOCKED;
		reset_lim = 0;
		return 0;
	} else {
		// Check whether needs questions to reset
		if (this->para.size()) {
			// Has questions to be answered
			prompt_info(info::AUTHENTICATION_REQUIRED);
			int i = 1;
			for (menu::para_map::iterator it = para.begin(); it != para.end(); ++it, ++i) {
				std::string prmt = "Question #";
				prmt += std::to_string(i);
				prmt += "\t: ";
				prmt += it->first;
				std::string ans = prompt_input(prmt);
				if (it->second != ans) {
					// Incorrect answer
					prompt_abortion(abortion::ANSWER_MISMATCHED);
					return -1;
				} else
					prompt_info(info::ANSWER_MATCHED);
			}
			prompt_info(info::QUESTIONS_AUTHENTICATION_PASSED);
		}
		if (!this->parent->remove_para(this->user)) {
			// User not found
			prompt_debug(this->user + debug::SYSTEM_USER_NOT_DEFINED);
		}
		// Re-add user
		this->parent->add_para(this->user, this->reset_password);
		// Disable reset
		reset_lim = 0;
		return 1;
	}
}

/*	*	*	*	*	*	PUBLIC FUNCTION		*	*	*	*	*	*/

void account::attempt() {
	// Check whether it is possible to reset
	if (reset_lim > 0) {
		if (++fail >= reset_lim) {
			prompt_warning(warning::PASSWORD_LIMIT_REACHED);
			switch (this->reset()) {
				case 1:
					prompt_info(info::PASSWORD_RESET_SUCCESS);
					break;
				case 0:
					prompt_warning(abortion::ACCOUNT_ACCESS_DENIED_ERROR_LOCKED);
					break;
				case -1:
					prompt_info(info::PASSWORD_RESET_FAILED);
					break;
				default:
					break;
			}
			this->back();
		}
	}
}

void account::entered() {
	((mailbox*) in)->refresh();
	((mailbox*) out)->refresh();
	this->prompt_welcome();
}

void account::send(const std::string& to, const std::string& content, std::vector<menu**>* maillist) {
	menu* ret = ((mailbox*) out)->interact(to, content, maillist);
	// Add to maillist
	maillist->push_back(&ret);
	if (this->parent->has_cmd(to)) {
		account* rec = (account*) this->parent->find_cmd(to)->second;
		rec->receive(this->caption, content, maillist);
	} else {
		prompt_debug(to + debug::MAIL_USER_NOT_DEFINED + user);
	}
}

void account::receive(const std::string& from, const std::string& content, std::vector<menu**>* maillist) {
	menu* ret = ((mailbox*) in)->interact(from, content, maillist);
	// Add to maillist
	maillist->push_back(&ret);
}

void account::change_name(const std::string& str) {
	if (this->user != str) {
		this->user = str;
		this->set_info("Welcome, " + user);
	}
}

