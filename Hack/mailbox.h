/*
	mailbox.h

	This class is a mailbox.
	This class is defined abstract. Only pointer or reference is allowed.

	Created on 052414
	Author: Anoxic

	*/

#pragma once

#include <string>

#include "mail.h"
#include "menu.h"

class mailbox: public menu {
	/* The index of mails, starting from 1 because in generate_mail() the index will be incremented */
	int index;
	menu* refresh_menu;

	void act(const std::string&, const std::string&);
	void display_help();
	void init();
protected:
	/*
	 Return the mail index in *** format
	 This function is called each time when a new message is generated
	 */
	const std::string get_index() const;
	void set_index(int i) {
		this->index = i;
	}
	/* Return added index but will NOT increment index by one */
	const std::string get_added_index() {
		++index;
		// Stores added index
		std::string tmp = get_index();
		// Resume added index
		--index;
		return tmp;
	}
	/* Return added index and increment index by one */
	const std::string add_index() {
		++index;
		return get_index();
	}

	/* Get the recipient from get_desc() of menu(mail) */
	const std::string get_recipient(menu*);
	/* Get the sender from get_desc() of menu(mail) */
	const std::string get_sender(menu*);
	/* Get summary (30 characters) from mail(menu) */
	const std::string get_summary(menu*);
public:
	// The parent of mailbox is thought to be "account"
	mailbox(menu* par, const std::string& title, const std::string& info): index(0), menu(par, title, "", info) {
		init();
	}
	virtual ~mailbox() {
		for (menu::menu_map::iterator it = cmd.begin(); it != cmd.end(); ++it)
			delete it->second;
	}

	/*
	 Generate a mail by specifying the sender, content and receiver
	 Mail index will NOT be incremented (for this mailbox)
	 @Return a pointer to "mail" declared as a pointer to "menu"
	 */
	menu* generate_mail(const std::string&, const std::string&, const std::string&);

	void entered() {
		// Refresh this mailbox (reset mail read status)
		this->refresh();
		prompt_welcome();
	}

	/* Refresh this mailbox; output nothing */
	virtual void refresh() = 0;
	/*
	 Interact with someone: send or receive letters 
	 The index will finally be incremented in mailbox::interact(menu* m)
	 */
	virtual void interact(menu* m, menu::maillist_vector* maillist) = 0;
	virtual menu* interact(const std::string& who, const std::string& content, menu::maillist_vector* maillist) = 0;
};

