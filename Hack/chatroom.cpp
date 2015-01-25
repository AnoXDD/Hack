/*
* chatroom.h
*
*  Created on: June 21, 2014
*      Author: Anoxic
*/

#include "stdafx.h"

#include <Windows.h>

#include "chatroom.h"
#include "dialog.h"

void chatroom::act(const std::string& name, const std::string& para) {
	if (name == "enter") {
		if (status == 0) {
			/* History logger */
			std::string log;
			std::vector<std::string>::const_iterator it1 = dialog::story::CHATROOM.cbegin();
			std::vector<int>::const_iterator it2 = dialog::story::CHATROOM_INTERVAL.cbegin();
			for (; it1 != dialog::story::CHATROOM.cend(); ++it1, ++it2) {
				// Log the history
				log += (*it1 + "\n");
				// Prompt it
				prompt_plain(*it1);
				// Wait for next message
				Sleep(*it2);
			}
			status++;
			// Change the permission to access
			enter->set_info(dialog::info::CHATROOM_ACCESS_DENIED);
			// Change the history of chatroom
			history->set_info(dialog::info::CHATROOM_DISPLAY_HISTORY);
			history->set_desc(log);
		}
	} else if (name == "history") {

	}
}

void chatroom::init() {
	enter = new menu(this, "enter");
	history = new menu(this, "history");
	history->set_info(dialog::info::CHATROOM_NO_HISTORY);
	this->add_cmd("enter", enter);
	this->add_cmd("history", history);
}


