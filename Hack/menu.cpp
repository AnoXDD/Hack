/*
 * menu.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: Ano
 */

#include "stdafx.h"

#include <utility>

#include "command_catalog.h"
#include "menu.h"
#include "dialog.h"

using namespace dialog;

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/ 

void menu::act(const std::string& name, const std::string& para) {
	// User prompts quit the game
	if (name == "exit") {

	}
}

void menu::display_help() {
	prompt_info(info::HELP_FILE_HEADER);
	// Display two basic help menu
	prompt_help("..");
	prompt_help("?");
	// Iterate to display all available commands
	for (menu_map::iterator it = cmd.begin(); it != cmd.end(); ++it)
		prompt_help(it->first);
}

void menu::refresh_child_dir() {
	for (menu_map::iterator it = (this->cmd).begin(); it != (this->cmd).end(); ++it) {
		// Refresh the child directory
		it->second->set_dir(this->dir + this->caption + "/");
		// Refresh the child's child directory by recursion
		it->second->refresh_child_dir();
	}
}

/*	*	*	*	*	*	PUBLIC FUNCTION		*	*	*	*	*	*/

menu* menu::back() {
	if (returnable) {
		prompt_info(info::RETURN_TO_PREVIOUS);
		parent->entered();
		return parent;
	} else {
		prompt_abortion(abortion::RETURN_NOT_ALLOWED);
	}
	return this;
}

menu* menu::enter(const std::string& name, const std::string& para_str) {
	// Return prompt
	if (name == ".." && para_str == "") {
		return this->back();
	}
	// Help menu display
	if (name == "help" || name == "?") {
		this->display_help();
		return this;
	}
	// Name validity check
	if (cmd.find(name) == cmd.end()) {
		this->prompt_invalid_command(name);
		return this;
	} else {
		/* The menu that is about to enter in */
		menu* ret = cmd.find(name)->second;
		// Test the validity of input parameters
		/* The validity of parameters */
		bool flag = true;
		if (ret->is_auth()) {
			if (para_str != "") {
				// Authetication required; must be a "system" class, but "system" does not allow parameters provided by user
				this->prompt_unnecessary_params(name);
				flag = false;
			}
		} else {
			if (ret->get_para_size() != 0) {
				// Parameters required
				if (para_str == "") {
					// Parameters required but not offered by user
					this->prompt_missing_params(name);
					flag = false;
				} else if (!ret->has_para(para_str)) {
					// Such parameter not found
					this->prompt_invalid_params(name, para_str);
					flag = false;
				}
			} else if (para_str != "") {
				// No parameters required but offered by user
				prompt_abortion(abortion::UNNECESSARY_PARAMETERS + name);
				flag = false;
			}
		}
		if (flag) {
			// Parameters test passed
			this->act(name, para_str);
			ret->entered();
		} else {
			// Parameters test failed; no further access needed
			return this;
		}
		if (ret->get_cmd_size() == 0) {
			// Empty menu; display information only
			return this;
		} else if (!ret->is_auth()) {
			// No further process needed
			return ret;
		} else {
			// "system" class
			prompt_info(info::AUTHENTICATION_REQUIRED);
			std::pair<std::string, std::string> str_pair = prompt_login();
			return ret->enter(str_pair.first, str_pair.second);
		}
	}
}

void menu::prompt_welcome() const {
	if (!this->cmd.empty()) {
		// Display directory only if the menu is not empty
		prompt_separator();
	}
	prompt_info(this->info);
	prompt_plain(this->desc);
}
