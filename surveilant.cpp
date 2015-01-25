/*
surveilant.cpp

Created @ 062914 1329
Author: Anoxic

*/

#include "stdafx.h"

#include "dialog.h"
#include "surveilant.h"

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void surveilant::act(const std::string& name, const std::string& para) {
	if (locked) {
		// Operation not available
		prompt_abortion(dialog::abortion::SURVEILANT_THROTTLED);
	} else {
		if (name == "disable") {
			this->disable_system(para);
		} else if (name == "enable") {
			this->enable_system(para);
		}
	}
}

void surveilant::init() {
	// Initialize two important components
	info = dialog::info::SURVEILANT_HEADER + parent->get_caption();
	desc = dialog::info::SURVEILANT_STATUS_ENABLED;
	// Its info is subjected to change due to different params
	disable = new menu(this, "Disable");
	enable = new menu(this, "Enable", "", dialog::info::SURVEILANT_ENABLED);
	log = new menu(this, "Log", dialog::story::LOG_OLD, dialog::info::SURVEILANT_LOG_HEADER);
	// Add commands
	this->add_cmd("disable", disable);
	this->add_cmd("enable", enable);
	this->add_cmd("log", log);
	// Add parameter
	disable->add_para("all", "");
	enable->add_para("all", "");
}

void surveilant::lock() {
	locked = true;
	// Enable and disable info cleared
	disable->set_info("");
	enable->set_info("");
}

void surveilant::disable_system(const std::string& ID) {
	if (ID == "all") {
		// Test if it has been disabled before
		if (disable->get_info() == dialog::info::SURVEILANT_DISABLING_SUCCESSFUL) {
			disable->set_info(dialog::info::SURVEILANT_DISABLED);
		} else if (disable->get_info() != dialog::info::SURVEILANT_DISABLED) {
			// The system is not yet disabled
			// Ask the user to continue
			std::string ret = prompt_input(dialog::info::SURVEILANT_DISABLE_CONFIRM);
			if (ret == "y") {
				// User continues
				prompt_info(dialog::info::SURVEILANT_DISABLING + "all ...");
				disable->set_info(dialog::info::SURVEILANT_DISABLING_SUCCESSFUL);
				// Set as empty to indicate that enabling is enabled
				enable->set_info("");
				// Change menu description
				this->desc = dialog::info::SURVEILANT_STATUS_DISABLED;
				// Test if qualified for lock
				if (enable->get_para_size() == 1 && disable->get_para_size() == 1) {
					// First step: disable entire system
					lock();
				}
			} else {
				// User aborts
				disable->set_info("");
			}
		}
	} else if (ID == dialog::story::ID_ECHO) {
		prompt_info(dialog::info::SURVEILANT_DISABLING + "this ID ...");
		disable->set_info(dialog::info::SURVEILANT_DISABLING_SUCCESSFUL);
		// Test if qualified for lock
		if (is_enabled()) {
			// The whole system is enabled
			lock();
		}
	}
}

void surveilant::enable_system(const std::string& ID) {
	if (ID == "all") {
		// Test if it has been enabled before
		if (enable->get_info() == dialog::info::SURVEILANT_ENABLING_SUCCESSFUL) {
			enable->set_info(dialog::info::SURVEILANT_ENABLED);
		} else if (enable->get_info() != dialog::info::SURVEILANT_ENABLED) {
			// The system is not yet enabled
			prompt_info(dialog::info::SURVEILANT_ENABLING + "all ...");
			enable->set_info(dialog::info::SURVEILANT_ENABLING_SUCCESSFUL);
			// Set as empty to indicate that disabling is enabled
			disable->set_info("");
			// Change menu description
			this->desc = dialog::info::SURVEILANT_STATUS_ENABLED;
			// Update log
			this->update_log();
		}
	} else if (ID == dialog::story::ID_FOXTROT) {
		prompt_info(dialog::info::SURVEILANT_ENABLING + "this ID ...");
		enable->set_info(dialog::info::SURVEILANT_ENABLING_SUCCESSFUL);
		// Test if qualified for lock
		if (is_enabled()) {
			// The whole system is enabled too
			lock();
		}
	}
	// Refresh status
	this->entered();
}

/*	*	*	*	*	*	PUBLIC FUNCTION	*	*	*	*	*	*/

void surveilant::damage_system() {
	// Invalidate the command
	this->remove_cmd("disable");
	this->remove_cmd("enable");
	log->set_desc(dialog::story::LOG_OLD);
}

void surveilant::unlock(bool is_enabled) {
	locked = false;
	if (is_enabled) {
		// Change status
		this->desc = dialog::info::SURVEILANT_STATUS_ENABLED;
		// Set menu info
		enable->set_info(dialog::info::SURVEILANT_ENABLED);
		disable->set_info(dialog::info::SURVEILANT_DISABLING);
	} else {
		this->desc = dialog::info::SURVEILANT_STATUS_DISABLED;
		enable->set_info(dialog::info::SURVEILANT_ENABLING);
		disable->set_info(dialog::info::SURVEILANT_DISABLED);
	}
}
