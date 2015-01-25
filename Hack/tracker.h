/*
 tracker.h

 Track the progress of the game

 Created on 062714
 Author: Anoxic

 */


#pragma once

#include "dialog.h"
#include "menu.h"

class tracker: public menu {
private:
	/* Refer to the level */
	int &level;
	/* This menu is deliberately added to avoid this class being a display-only menu */
	menu* all;

	void init();

	void act(const std::string&, const std::string& = "");
	void display_all();
	void refresh_desc();
	void refresh_info();
public:
	tracker(menu* par, int& ref_level): menu(par, "Story", dialog::story::WELCOME), level(ref_level) {
		init();
	}
	virtual ~tracker() {
		delete all;
	}

	// Display the entire story line
	std::string get_all_story();

	/* Refresh this tracker*/
	void refresh() {
		refresh_info();
		refresh_desc();
	}
};

