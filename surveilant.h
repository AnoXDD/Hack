/*
surveilant.h

The surveillance system of maco

Created @ 062914 1326
Author: Anoxic

*/

#pragma once

#include <string>

#include "menu.h"

class surveilant: public menu {
	/* After each story-triggering step, this is set to true */
	bool locked;
	menu *disable, *enable, *log;

	void act(const std::string&, const std::string& = "");
	void init();

	void prompt_invalid_params(const std::string& name, const std::string& para_str) {
		prompt_abortion(para_str + " : " + dialog::abortion::SURVEILANT_INVALID_PARAMETERS);
	}
	void prompt_missing_params(const std::string& name) {
		prompt_abortion(dialog::abortion::SURVEILANT_MISSING_PARAMETERS + name);
	}

	/* These two functions are for private use only; they do not technically denote their names */
	bool is_enabled() const {
		return (enable->get_info() == dialog::info::SURVEILANT_ENABLING_SUCCESSFUL || enable->get_info() == dialog::info::SURVEILANT_ENABLED);
	}
	bool is_disabled() const {
		return (disable->get_info() == dialog::info::SURVEILANT_DISABLING_SUCCESSFUL || disable->get_info() == dialog::info::SURVEILANT_DISABLED);
	}
	/*
	 Disable/enable system
	 The ID passed in must be legal because it passed enter() test
	 */
	void disable_system(const std::string& ID);
	void enable_system(const std::string& ID);
	/* Lock this system so that it cannot be operated */
	void lock();

	/* Update the log; will be called when enable_system(const std::string&) is called */
	void update_log() {
		log->set_desc(dialog::story::LOG_NEW);
	}
public:
	/* Its parent shuold be "account" because here the program automatically gets the caption of its parent to initialize its caption */
	surveilant(menu* par, const std::string& title): menu(par, title) {
		init();
	}
	~surveilant() {
		delete disable;
		delete enable;
		delete log;
	}

	void add_disable_ID(const std::string& ID) {
		disable->add_para(ID, "");
	}
	void remove_disable_ID(const std::string& ID) {
		disable->remove_para(ID);
	}
	void add_enable_ID(const std::string& ID) {
		enable->add_para(ID, "");
	}
	void remove_enable_ID(const std::string& ID) {
		enable->remove_para(ID);
	}

	void damage_system();

	bool is_locked() const {
		return locked;
	}
	/*
	 Enable user to operate on the surveillance system with a status
	 If is_enabled is true, then the status is enabled (default); otherwise disabled
	 */
	void unlock(bool is_enabled = true);
};

