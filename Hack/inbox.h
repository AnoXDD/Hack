/*
	inbox.h

	Created on 052414
	Author: Anoxic

	*/

#pragma once

#include "dialog.h"
#include "mailbox.h"

class inbox: public mailbox {
	void init();
public:
	inbox(menu* parent, const std::string& title = "Inbox"): mailbox(parent, title, dialog::info::MAILBOX_NO_NEW_MAILS) {
		init();
	}
	~inbox() {}

	/*
	 Receive a "mail" directly
	 This pointer to menu should be a pointer to "mail".
	 */
	void interact(menu* m, menu::maillist_vector* maillist);
	/*
	 Receive a letter from others; auto-format
	 The new letter will be automatically labeled as "new"
	 Return the pointer to the newly created mail object
	 */
	menu* interact(const std::string& who, const std::string& content, menu::maillist_vector* maillist);
	/*
	 Refresh the mailbox
	 If any major changes occur, do not forget to make corresponding changes to another "mailbox"
	 */
	void refresh();
};

