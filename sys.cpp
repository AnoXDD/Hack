/*
* sys.cpp
*
*  Created on: May 20, 2014
*      Author: Anoxic
*/

#include "stdafx.h"

#include "account.h"
#include "dialog.h"
#include "sys.h"

using namespace dialog;

menu* sys::enter(const std::string& user, const std::string& password) {
	menu_map::iterator cmd_it = cmd.find(user);
	if (cmd_it != cmd.end()) {
		// User found
		para_map::iterator para_it = para.find(user);
		if (para_it != para.end()) {
			// This user's password is stored
			if (para_it->second == password) {
				// Username and password matched
				prompt_info(info::AUTHENTICATION_PASSED);
				cmd_it->second->entered();
				return cmd_it->second;
			} else {
				// Username and password mismatched
				prompt_abortion(abortion::USERNAME_AND_PASSWORD_MISMATCHED);
				// This account has been attempted once
				((account*) cmd_it->second)->attempt();
				return this->parent;
			}
		} else {
			/*
			This user exists but the program does not allow the player to log in with this account by removing its username/password pair from the para list.
			When this happens, ususally the program wants to display something from the account's description.
			*/
			prompt_abortion(cmd_it->second->get_desc());
			return this->parent;
		}
	} else {
		// No user found
		prompt_abortion(abortion::USERNAME_AND_PASSWORD_MISMATCHED);
		return this->parent;
	}
}
