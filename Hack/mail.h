/*
 * mail.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Ano
 */

#ifndef MAIL_H_
#define MAIL_H_

#include <string>

#include "menu.h"

class mail: public menu {
	/*
	 The read status of this mail, whether this mail has been replied and whether this mail has been retrieved
	 It is true by default, which means it is read , not replied, not retrieved by default
	 However, in call inbox::interact(menu*), variable "read" will be set to false.
	 */
	bool read;
	/*
	 Whether this mail has been replied and whether this mail has been retrieved
	 They are all false by default, which means this mail is not replied, not retrieved by default
	 */
	bool replied, retrieved;
	/* Downloadable content
	 0 if current mail has nothing to download (default value)
	 Positive value to indicate different things to download
	 Each attachment can only be "downloaded" once
	 */
	int attachment;
	/* Details of the mail 
	 For string "recipient" and "sender", they will be initialized in mailbox::generate_mail(*PARAMS*). Besides, they are all mail addresses with @
	 For string "time", it will be initialzied in this->init(const std::string&)
	 */
	std::string recipient, sender, current_time;
	/* Detail list menu */
	menu* detail;
	/* This menu would only be displayed if "attachment" has value other than 0 */
	menu* transmit;
	/*
	 Three basic menus to display
	 The user can control their attribute using public functions provided
	 Reply and retrieve functions are both disabled by default, and they are not added to functions by default
	 */
	menu *unread, *reply, *retrieve;

	void act(const std::string&, const std::string& = "");
	void init(const std::string& = "");

	void prompt_attachment();

	/* Return current time */
	std::string get_time();
	void refresh_detail();
public:
	/* The title is the index of this mail */
	mail(menu* mailbox, const std::string& title, const std::string& content): read(true), replied(false), retrieved(false), attachment(0), recipient(""), sender(""), current_time(""), menu(mailbox, title) {
		init(content);
	}
	~mail() {
		delete detail;
		delete unread;
		delete reply;
		delete retrieve;
		delete transmit;
	}

	const bool is_read() const {
		return read;
	}
	void set_read(bool flag) {
		read = flag;
	}

	int get_attachment() const {
		return attachment;
	}
	void set_attachment(int value) {
		// Test value validity
		if (value < 0)
			prompt_debug(dialog::debug::INVALID_MAIL_ATTACHMENT_INDEX);
		else {
			attachment = value;
			if (value == 0)
				this->remove_cmd("transmit");
			else
				this->add_cmd("transmit", transmit);
		}
		this->refresh_detail();
	}

	/* Add reply function */
	void add_reply() {
		this->add_cmd("reply", reply);
	}
	void disable_reply() {
		reply->set_info(dialog::info::MAIL_REPLY_DISABLED);
	}
	void enable_reply() {
		replied = false;
		reply->set_info(dialog::info::MAIL_REPLY_ENABLED);
	}
	/* Remove reply function */
	void remove_reply() {
		this->remove_cmd("reply");
	}
	bool is_reply_enabled() {
		return (reply->get_info() == dialog::info::MAIL_REPLY_ENABLED);
	}
	bool is_replied() {
		return replied;
	}

	/* Add retrieve function */
	void add_retrieve() {
		this->add_cmd("retrieve", retrieve);
	}
	void disable_retrieve() {
		retrieve->set_info(dialog::info::MAIL_RETRIEVAL_DISABLED);
	}
	void enable_retrieve() {
		retrieved = false;
		retrieve->set_info(dialog::info::MAIL_RETRIEVAL_ENABLED);
	}
	/* Remove retrieve function */
	void remove_retrieve() {
		this->remove_cmd("retrieve");
	}
	bool is_retrieve_enabled() {
		return (retrieve->get_info() == dialog::info::MAIL_RETRIEVAL_ENABLED);
	}
	bool is_retrieved() {
		return retrieved;
	}

	/* Recipient adjustment */
	const std::string get_recipient() const {
		return this->recipient;
	}
	void set_recipient(const std::string& str) {
		this->recipient = str;
	}

	/* Sender adjustment */
	const std::string get_sender() const {
		return this->sender;
	}
	void set_sender(const std::string& str) {
		this->sender = str;
	}

	void entered() {
		// This mail is read
		read = true;
		prompt_welcome();
		prompt_attachment();
		refresh_detail();
	}
};

#endif /* MAIL_H_ */
