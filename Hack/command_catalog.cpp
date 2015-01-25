/*
 * command_catelog.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Anoxic
 */

#include "stdafx.h"

#include "command_catalog.h"

void command_catalog::init() {
	/* PLEASE KEEP THE COMMAND HELP FILE HERE SORTED ALPHABETICALLY */
	command[".."] = "Back to previous menu";
	command["?"] = "Display this help menu";
	command["[Ltr. No.]"] = "Input the 3-digit index of the letter to read";
	command["accept"] = "Accept the task on the list";
	command["all"] = "Display all the information";
	command["chat"] = "Enter the chatroom";
	command["comm"] = "Log in COMM system";
	command["detail"] = "Display more details about this mail";
	command["disable"] = "Disable surveillance system for someone or for all";
	command["enable"] = "Enable surveillance system for all";
	command["enter"] = "Enter the room";
	command["history"] = "Review the history";
	command["inbox"] = "Enter mail inbox of this account";
	command["install"] = "Install available plugins";
	command["log"] = "View log file";
	command["maco"] = "Log in MACO system";
	command["mia"] = "Enter MIA system";
	command["objective"] = "View your current objective";
	command["outbox"] = "Enter mail outbox of this account";
	command["plugin"] = "See installed and available plugins";
	command["refresh"] = "Manually refresh this mailbox";
	command["reply"] = "Reply the current mail";
	command["retrieve"] = "Retrieve the current mail";
	command["start"] = "Start the game";
	command["story"] = "Tell everything that has happened until now";
	command["submit"] = "Submit your information cracked from intelligence";
	command["surveil"] = "Enter surveillance system";
	command["task"] = "Review task list";
	command["transmit"] = "Transmit the attachment to local";
	command["uninstall"] = "Uninstall installed plugins";
	command["unread"] = "Mark this mail as unread";
	command["view"] = "View plugins status";
}

const std::string command_catalog::operator[](const std::string& key) const {
	std::map<std::string, std::string>::const_iterator it = command.find(key);
	std::string ret;
	if (it == command.end()) {
		// not found
		ret = "";
	} else {
		// found
		ret = ": " + it->second;
	}
	return ret;
}

