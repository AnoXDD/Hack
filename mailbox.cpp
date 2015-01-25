/*
	mailbox.cpp

	Created on 052414
	Author: Anoxic
	*/

#include "stdafx.h"

#include "account.h"
#include "command_catalog.h"
#include "dialog.h"
#include "mailbox.h"

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void mailbox::act(const std::string& name, const std::string& para) {
	if (name == "refresh") {
		// entered() both refreshing the menu and prompt welcome
		this->entered();
	}
}

void mailbox::display_help() {
	prompt_info(dialog::info::HELP_FILE_HEADER);
	// Display two basic help menu
	prompt_help("..");
	prompt_help("?");
	prompt_help("[Ltr. No.]");
	prompt_help("refresh");
}

void mailbox::init() {
	refresh_menu = new menu(this, "refresh", "", dialog::info::MAILBOX_REFRESHING);
	this->add_cmd("refresh", refresh_menu);
}

/*	*	*	*	*	*	PROTECTED FUNCTION	*	*	*	*	*	*/

const std::string mailbox::get_index() const {
	std::string str = std::to_string(index);
	// Index overflowed
	if (str.size() > 3)
		prompt_debug(dialog::debug::MAILBOX_INDEX_OVERFLOW);
	// Add 0
	while (str.size() != 3)
		str = "0" + str;
	return str;
}

const std::string mailbox::get_recipient(menu* mail) {
	std::string str = mail->get_desc();
	std::string::iterator it = str.begin();
	// Point to the character next to "Dear "
	for (int i = 0; i != 5; ++i)
		++it;
	std::string ret;
	for (; it != str.end() && *it != ','; ++it) {
		// Add recipient character by character
		ret += *it;
	}
	if (it == str.end())
		// No recipient found
		return "";
	if (ret.length() > 7) {
		// Truncate the string
		return ret.substr(0, 5) + "..";
	} else {
		return ret;
	}

}

const std::string mailbox::get_sender(menu* mail) {
	std::string str = mail->get_desc();
	// Search from the end of the string
	std::string::reverse_iterator it = str.rbegin();
	for (; it != str.rend() && *it != ','; ++it) {
		// Do nothing
	}
	if (it == str.rend())
		// No sender found
		return "";
	// Make it point to the space after ","
	--it;
	// Point to the first char of the sender
	--it;
	std::string ret;
	// Move back
	while (it != str.rbegin()) {
		ret += *it;
		--it;
	}
	ret += *it;
	if (ret.length() > 7) {
		// Truncate the string
		return ret.substr(0, 5) + "..";
	} else {
		return ret;
	}
}

const std::string mailbox::get_summary(menu* mail) {
	std::string str = mail->get_desc();
	std::string::iterator it = str.begin();
	for (; it != str.end() && *it != ','; ++it) {
		// Do nothing
	}
	if (it == str.end())
		// No content found
		return dialog::info::MAILBOX_PREVIEW_NA;
	// Make it point to \n after ","
	++it;
	// Make it point to \t
	++it;
	// Make it point to the start of content
	++it;
	std::string ret;
	for (int i = 1; i != 30; ++i, ++it)
		ret += *it;
	ret += "...";
	return ret;
}

/*	*	*	*	*	*	PUBLIC FUNCTION	*	*	*	*	*	*/

menu* mailbox::generate_mail(const std::string& to, const std::string& content, const std::string& from) {
	std::string str = "Dear " + to + ",\n" + content + "\n\n" + dialog::mail::random_closing() + ",\n" + from;
	std::string index_str = get_added_index();
	menu* m = new mail(this, index_str, str);
	std::string suffix;
	// If the inbox is for the main menu, there is no variable called "address"
	if (from == "Pluto") {
		suffix = "@anoxic.me";
	} else {
		suffix = ((account*)this->parent)->get_address_suffix();
	}
	if (suffix != dialog::info::ADDRESS_UNDEFINED) {
		((mail*) m)->set_recipient(to + suffix);
		((mail*) m)->set_sender(from + suffix);
	} else {
		((mail*) m)->set_recipient(suffix);
		((mail*) m)->set_sender(suffix);
	}
	return m;
}

