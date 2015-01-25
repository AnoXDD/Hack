/*

task_menu.cpp

Created @ 070614 1152
Author: Anoxic

*/

#include "stdafx.h"

#include "dialog.h"
#include "task_menu.h"

#include <utility>


void task_menu::act(const std::string& name, const std::string& para) {
	if (name == "accept") {
		// Task accepted
		// Unnecessary to check para because the para has already passed the test
		prompt_info(dialog::info::TASK_OBJECTIVE_ACCEPTED);
		this->remove_cmd("accept");
		// Add objective view and submit function
		this->add_cmd("objective", objective);
		this->add_cmd("submit", submit);
		// What is submitted should be always pending (if it is not correct)
		submit->set_info(dialog::info::TASK_SUBMISSION_PENDING);
		// Disable task view
		desc = "";
		task->set_desc(dialog::info::TASK_OBJECTIVE_DISABLED);
	} else if (name == "submit") {
		// TODO wait for 3 seconds delay after each submission
		// Intelligence submission
		prompt_info(dialog::info::TASK_SUBMISSION_HEADER_ACCOUNT);
		std::pair<std::string, std::string> str_pair = prompt_login();
		if (str_pair.first == "Bandit" && str_pair.second == "9350422") {
			// Intelligence cracked!
			prompt_info(dialog::info::TASK_SUBMISSION_PENDING);
			// Display congratulations message
			submit->set_info(dialog::info::TASK_SUBMISSION_CORRECT);
			// Send signal
			accomplished = true;
			// Remove two menus
			this->remove_cmd("objective");
			this->remove_cmd("submit");
			// Update objective list view
			this->set_desc(dialog::info::TASK_OBJECTIVE_LIST_NEW);
			task->set_desc(dialog::info::TASK_OBJECTIVE_LIST_NEW);
		} 
		// else nothing to do
	}
}

void task_menu::init() {
	access_ID = "4D28E";
	// Task description
	desc = dialog::info::TASK_OBJECTIVE_LIST;
	accept = new menu(this, "Accept");
	accept->add_para("9432", "");
	objective = new menu(this, "Objective", dialog::info::TASK_OBJECTIVE_USER);
	submit = new menu(this, "Submit");
	task = new menu(this, "Task");
	// Sync display
	task->set_desc(this->desc);
	this->add_cmd("accept", accept);
	this->add_cmd("task", task);
}
