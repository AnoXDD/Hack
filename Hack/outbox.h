/*
	outbox.h

	Created on 052514
	Author: Anoxic
	*/


#pragma once

#include "dialog.h"
#include "mailbox.h"

class outbox: public mailbox {
	void init();
public:
	outbox(menu* parent, const std::string& title = "Outbox"): mailbox(parent, title, dialog::info::MAILBOX_NO_NEW_MAILS) {
		init();
	}
	~outbox() {}

	/* Send a "mail" passed as a param */
	void interact(menu* m, std::vector<menu**>* maillist);
	/*
	 Send a letter from others; auto-format
	 */
	menu* interact(const std::string& who, const std::string& content, std::vector<menu**>* maillist);
	/*
	Refresh the mailbox
	If any major changes occur, do not forget to make corresponding changes to another "mailbox"
	*/
	void refresh();
};

