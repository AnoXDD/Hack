/*
 * chatroom.h
 * 
 * This class will be only used once in HACK I. 
 *
 *  Created on: June 21, 2014
 *      Author: Anoxic
 */

#pragma once

#include <string>

#include "dialog.h"
#include "menu.h"

class chatroom:	public menu {
	/* The number that indicates this meny is locked */
	const int LOCK_STATUS = 1;
	/*
	 This variable is used to denote which segment of chat messages to be extracted from the data base.
	 Although in the first chapter of the game there will only be one single time that the user has to access this, it is not guaranteed that in the future update more chatroom access will be enabled
	 If that is happening, this variable can be used as an indicator to help tell which messages (vector) to extract. 
	 This variable is set to 0 by default, and is set to 1 after first access and locked until the game is over. 
	 */
	int status;
	menu *enter, *history;

	void act(const std::string&, const std::string& = "");
	void init();
public:
	chatroom(menu* account): menu(account, "Chatroom", "", dialog::info::CHATROOM_WELCOME), status(0) {
		init();
	}
	virtual ~chatroom() {
		delete enter;
		delete history;
	}

	/* 
	 Lock the system manually, to be called again even after this is already lockes
	 Used to prevent this start again after the archive is loaded
	 */
	void lock() {
		this->status = this->LOCK_STATUS;
	}
	const int get_status() const {
		return status;
	}
};

