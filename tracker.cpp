/*
 tracker.cpp

 Created on 062714
 Author: Anoxic

 */

#include "stdafx.h"

#include <string>

#include "dialog.h"
#include "tracker.h"

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void tracker::init() {
	std::string str = std::to_string(level);
	this->info = dialog::info::LEVEL_DISPLAY + str;
	all = new menu(this, "All", "", dialog::info::STORY_ALL_ENDER);
	this->add_cmd("all", all);
}

void tracker::act(const std::string& name, const std::string& para) {
	if (name == "all") {
		prompt_plain(dialog::story::WELCOME);
		// Iterate to display story line
		for (int i = 0; i != level; ++i) {
			std::string header = "[LEVEL " + std::to_string(i) + "]";
			prompt_plain(header);
			prompt_plain(dialog::story::STORY[i]);
		}
	}
}

void tracker::refresh_desc() {
	if (level >= 0)
	this->desc = dialog::story::STORY[level];
}

void tracker::refresh_info() {
	std::string str = std::to_string(level);
	this->info = dialog::info::LEVEL_DISPLAY + str;
}

