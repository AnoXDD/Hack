/*

plugin.cpp

Created @ 070214 1102
Author: Anoxic

*/

#include "stdafx.h"

#include "dialog.h"
#include "plugin.h"

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void plugin::act(const std::string& name, const std::string& para) {
	if (name == "view") {
		refresh_display();
	} else {
		// Test if para is empty string
		if (para == "") {
			// If is, then no available para for install and uninstall, and thus no available plugins
			prompt_info(dialog::info::PLUGIN_EMPTY);
			// Avoid strange display
			install->set_info("");
			uninstall->set_info("");
		} else {
			if (name == "install") {
				this->install_plugin(para);
			} else if (name == "uninstall") {
				this->uninstall_plugin(para);
			}
		}
	}
}

void plugin::init() {
	install = new menu(this, "Install");
	uninstall = new menu(this, "Uninstall");
	// The display of this menu is always the same as plugin
	view = new menu(this, "View", this->desc, this->info);
	this->add_cmd("install", install);
	this->add_cmd("uninstall", uninstall);
	this->add_cmd("view", view);
}

void plugin::install_plugin(const std::string& para) {
	if (table.find(para)->second) {
		// Installed
		install->set_info(dialog::info::PLUGIN_INSTALLED);
	} else {
		// Not installed
		prompt_info(dialog::info::PLUGIN_INSTALLING);
		install->set_info(dialog::info::PLUGIN_INSTALLING_SUCCESSFUL);
		// Change key value
		table[para] = true;
		// Change para list
		install->remove_para(para);
		uninstall->add_para(para, "");
	}
}

void plugin::uninstall_plugin(const std::string& para) {
	if (!table.find(para)->second) {
		// Uninstalled
		uninstall->set_info(dialog::info::PLUGIN_UNINSTALLED);
	} else {
		// Installed
		prompt_info(dialog::info::PLUGIN_UNINSTALLING);
		uninstall->set_info(dialog::info::PLUGIN_UNINSTALLING_SUCCESSFUL);
		// Change key value
		table[para] = false;
		// Change para list
		uninstall->remove_para(para);
		install->add_para(para, "");
	}
}

void plugin::refresh_display() {
	if (table.size() == 0) {
		// No available plugin, clear everything
		this->info = dialog::info::PLUGIN_EMPTY;
		this->desc = "";
		install->set_info(dialog::info::PLUGIN_EMPTY);
		uninstall->set_info(dialog::info::PLUGIN_EMPTY);
	} else {
		// Iterate to operate
		this->info = "";
		this->desc = dialog::info::PLUGIN_HEADER;
		for (std::map<std::string, bool>::iterator it = table.begin(); it != table.end(); ++it) {
			this->desc += "\n" + it->first + "\t";
			// Install status
			this->desc += (it->second ? "Yes" : "No");
			this->desc += "\t" + this->interpret(it->first);
		}
	}
	// Refresh "view"
	view->set_info(this->info);
	view->set_desc(this->desc);
}

void plugin::refresh_para() {
	// Clear para list
	install->clear_para();
	uninstall->clear_para();
	for (std::map<std::string, bool>::iterator it = table.begin(); it != table.end(); ++it) {
		// Test whether it is installed
		if (it->second)
			// Installed
			uninstall->add_para(it->first, "");
		else
			// Uninstalled
			install->add_para(it->first, "");
	}
}

std::string plugin::interpret(const std::string& ID) const {
	if (ID == "705F5") {
		return "Comm Access Plugin";
	} else if (ID == "705F6") {
		return "Comm Access Plugin w/ Elevated Permission";
	} else if (ID == "964B8") {
		return "Maco Access Plugin";
	} else if (ID == "964B9") {
		return "Maco Access Plugin w/ Elevated Permission";
	} else if (ID == "964C9") {
		return "Maco Chatroom Access Plugin";
	} else if (ID == "2D0BE") {
		return "Maco Surveillant System Administrator Access Plugin";
	} else if (ID == "4D28E") {
		return "MIA Access Plugin";
	} else if (ID == "14FC6") {
		return "Comm Access Plugin w/ Elevated Permission";
	} else if (ID == "84A78"){
		return "MACO access plugin v2";
	} else {
		return "";
	}
}

/*	*	*	*	*	*	DEBUG FUNCTION	*	*	*	*	*	*/

void plugin::install_all() {
	if (DEBUG_MODE) {
		// Iterate to process all the plugins
		for (std::map<std::string, bool>::iterator it = table.begin(); it != table.end(); ++it) {
			// Table fix
			it->second = false;
			// Install the plugin
			install_plugin(it->first);
		}
	}
}

/*	*	*	*	*	*	PUBLIC FUNCTION	*	*	*	*	*	*/

void plugin::add_plugin(const std::string& ID) {
	table.insert(std::make_pair(ID, false));
	// Plugins are not installed by default
	install->add_para(ID, "");
	this->refresh_display();
}

void plugin::remove_plugin(const std::string& ID) {
	table.erase(ID);
	// Refresh install and uninstall list 
	if (!install->remove_para(ID)) {
		// If install does not include this ID, then it must be in uninstall list
		uninstall->remove_para(ID);
	}
	this->refresh_display();
}

bool plugin::is_installed(const std::string& ID) {
	std::map<std::string, bool>::iterator result = table.find(ID);
	if (result == table.end()) {
		// No result found
		return false;
	} else {
		return result->second;
	}
}

