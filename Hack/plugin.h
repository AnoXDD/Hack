/*

plugin.h

Control the plugins of this user

Things to change/add to add a new plugin:
1. The list below
2. The comment in dialog.cpp
3. Explanatory function plugin::interpret(const std::string&) in plugin.cpp

----[Plugin ID and interpretation quick view]----
	[ID]	[Interpretation]
100	705F5	COMM access plugin
101	705F6	COMM access plugin w/ elevated permission
102	964B8	MACO access plugin
103	964B9	MACO access plugin w/ elevated permission
104	964C9	MACO chatroom access plugin
105	2D0BE	MACO Surveillant system access plugin
106	4D28E	MIA access plugin
107	14FC6	[FAKE] COMM access plugin w/ elevated permission
108	84A78	MACO access plugin v2
109	10827
110	305F2
	EEA35
	C9680
	13827
	A8780
	CEBFD
	D5032
	B8C6F

Created @ 070214 1101
Author: Anoxic

*/

#pragma once

#include "stdafx.h"

#include <map>
#include <string>

#include "dialog.h"
#include "menu.h"

class plugin: public menu {
	/* Three basic menus */
	menu *install, *uninstall, *view;
	/*
	 Describe avaliable list and whether it is installed
	 [first] std::string: THE !!!ID!!! of the plugin
	 [second] bool: true if installed
	 NOTE: if [second] is true, it should be in "uninstall" because it is installed!
	 */
	std::map<std::string, bool> table;

	void act(const std::string&, const std::string& = "");
	void init();

	void prompt_invalid_params(const std::string& name, const std::string& para_str) {
		prompt_abortion(para_str + " : " + dialog::abortion::PLUGIN_INVALID_PARAMETER);
	}
	void prompt_missing_params(const std::string& name) {
		prompt_abortion(dialog::abortion::PLUGIN_MISSING_PARAMETER);
	}

	/* Two functions to install and uninstall the plugins */
	void install_plugin(const std::string& name);
	void uninstall_plugin(const std::string& name);

	/* Two components to refresh different things */
	void refresh_display();
	void refresh_para();
	/* Refresh all: this->desc and this->info */
	void refresh_all() {
		refresh_display();
		refresh_para();
	}
	/* Interpret the ID to an understandable string */
	std::string interpret(const std::string& ID) const;
public:
	plugin(menu* par): menu(par, "Plugin", "", dialog::info::PLUGIN_EMPTY) {
		init();
	}
	~plugin() {
		delete install;
		delete uninstall;
		delete view;
	}

	/* DEBUG_MODE only function 
	 If DEBUG_MODE in game_core.cpp is false, this function will do nothing
	*/
	void install_all();

	/* Add available plugin by unique ID */
	void add_plugin(const std::string& ID);
	/* Remove available plugin by unique ID */
	void remove_plugin(const std::string& ID);

	/*
	 Test if the plugin has been installed
	 @Return: true if is installed; false otherwise or this ID is not found
	 */
	bool is_installed(const std::string& ID);

	void entered() {
		refresh_display();
		prompt_welcome();
	}
};

