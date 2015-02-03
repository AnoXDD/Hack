/*
	outbox.cpp

	Created on 052514
	Author: Anoxic
	*/

#include "stdafx.h"

#include <utility>

#include "dialog.h"
#include "mail.h"
#include "outbox.h"

void outbox::init() {
	this->set_info(dialog::info::MAILBOX_ALL_MAILS_SENT);
}

void outbox::interact(menu* m, std::vector<menu**>* maillist) {
	// Add to maillist
	maillist->push_back(&m);
	// Add retrieval command
	((mail*) m)->add_retrieve();
	// Index has been incremented inside generate_mail()
	std::string index_str = this->add_index();
	this->add_cmd(std::make_pair(index_str, m));
}

menu* outbox::interact(const std::string& to, const std::string& content, std::vector<menu**>* maillist) {
	menu* m = this->generate_mail(to, content, this->parent->get_caption());
	// Format mail content
	this->interact(m, maillist);
	return m;
}

void outbox::refresh() {
	/* The amount of unread mails */
	int unread = 0;
	// Refresh information (new letters)
	std::string str = dialog::info::MAILBOX_OUT_HEADER + "\n";
	// Fetch mail information
	const menu::menu_map ret_map = this->get_cmd();
	if (ret_map.size() == 1)
		// only "refresh" command
		return;
	for (menu::menu_map::const_reverse_iterator const_it = ret_map.rbegin(); const_it != ret_map.rend(); ++const_it) {
		// "refresh" command should not be added in
		if (const_it->first != "refresh") {
			// The read status of the mail
			if (!((mail*) const_it->second)->is_read()) {
				str += "New";
				++unread;
			}
			str += "\t";
			// Test if the mail has attachments
			if (((mail*) const_it->second)->get_attachment() != 0)
				str += "*";
			str += "\t";
			// Add basic information of unread mail
			str += const_it->first + "\t" + get_recipient(const_it->second) + "\t" + get_summary(const_it->second) + "\n";
		}
	}
	this->set_desc(str);
	if (unread != 0) {
		// Unread letters exist
		if (unread == 1) {
			this->set_info(dialog::info::MAILBOX_NEW_SINGLE_MAIL);
		} else {
			std::string tmp = std::string(dialog::info::MAILBOX_NEW_MAILS_1);
			tmp += std::to_string(unread);
			this->set_info(tmp + dialog::info::MAILBOX_NEW_MAILS_2);
		}
	} else {
		this->set_info(dialog::info::MAILBOX_NO_NEW_MAILS);
	}
}

