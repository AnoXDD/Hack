/*

task_menu.h
In fact this class is to implement "MIA" system.

Created @ 070614 1152
Author: Anoxic

*/

#pragma once

#include <string>

#include "dialog.h"
#include "menu.h"

class task_menu: public menu {
	/* Five basic menus for displaying only */
	menu *accept, *objective, *submit, *task;
	/* Indicate whether the user has accomplished the only one task*/
	bool accomplished;

	void act(const std::string&, const std::string&);
	void init();

	void prompt_invalid_params(const std::string& name, const std::string& para_str) {
		prompt_abortion(para_str + " : " + dialog::abortion::TASK_INVALID_PARAMETERS_ID + " for " + name);
	}
	void prompt_missing_params(const std::string& name) {
		prompt_abortion(dialog::abortion::TASK_MISSING_PARAMETERS + name);
	}

	// TODO after accepting the objective the objective should be displayed automatically when the user enters
	void refresh_display();
public:
	task_menu(menu* par, const std::string& title): menu(par, title), accomplished(false) {
		init();
	}

	const bool is_accomplished() const {
		return accomplished;
	}

	~task_menu() {
		delete accept;
		delete objective;
		delete submit;
		delete task;
	}

};

