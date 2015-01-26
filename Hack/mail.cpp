/*
 * mail.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Ano
 */

#include "stdafx.h"

#include <ctime>

#include "dialog.h"
#include "mail.h"

/*	*	*	*	*	*	PRIVATE FUNCTION	*	*	*	*	*	*/

void mail::act(const std::string& name, const std::string& para) {
	if (name == "unread") {
		this->set_read(false);
	} else if (name == "reply") {
		if (this->is_reply_enabled()) {
			if (replied)
				// Change its caption
				reply->set_info(dialog::info::MAIL_REPLIED);
			else
				// Toggle replied status
				replied = true;
		}
	} else if (name == "retrieve") {
		if (this->is_retrieve_enabled()) {
			if (retrieved)
				// Change its caption
				retrieve->set_info(dialog::info::MAIL_RETRIEVED);
			else
				// Toggle retreived status
				retrieved = true;
		}
	} else if (name == "transmit") {
		switch (attachment) {
			case 1:
			case 2:
			case 3: {
				bool flag = util::print_file(dialog::mail::ATTACHMENT_NAME[attachment], dialog::mail::ATTACHMENT[attachment]);
				if (flag) {
					prompt_info(dialog::info::MAIL_ATTACHMENT_TRANSMITTING);
					transmit->set_info(dialog::info::MAIL_ATTACHMENT_TRANSMITTED);
					// File transmission succeeded, disable the attachment
					this->set_attachment(0);
				} else {
					prompt_abortion(dialog::abortion::MAIL_ATTACHMENT_DOWNLOAD_FAILED);
					// No info displayed
					transmit->set_info("");
				}
				break;
			}
			case 100:
			case 101:
			case 102:
			case 103:
			case 104:
			case 105:
			case 106:
			case 107:
			case 108:
				// Plugin attachments, the process of "downloading" is completed in the codes of game_core.cpp
				prompt_info(dialog::info::MAIL_ATTACHMENT_TRANSMITTING);
				transmit->set_info(dialog::info::MAIL_ATTACHMENT_TRANSMITTED);
				this->set_attachment(0);
				break;
			default:
				break;
		}
	}
}

void mail::init(const std::string& str) {
	valid_attachment = {0,1, 2, 3, 100, 101, 102, 103, 104, 105, 106, 107, 108};
	// Time fixed
	current_time = get_time();
	detail = new menu(this, "detail");
	refresh_detail();
	unread = new menu(this, "unread", "", dialog::info::MAIL_SET_AS_UNREAD);
	this->info = dialog::info::MAIL_HEADER;
	this->desc = str;
	this->add_cmd("detail", detail);
	this->add_cmd("unread", unread);
	transmit = new menu(this, "transmit");
	reply = new menu(this, "reply", "", dialog::info::MAIL_REPLY_DISABLED);
	retrieve = new menu(this, "retrieve", "", dialog::info::MAIL_RETRIEVAL_DISABLED);
}

void mail::prompt_attachment() {
	if (attachment != 0) {
		if (attachment < 100) {
			prompt_plain("\n" + dialog::info::MAIL_ATTACHED + dialog::mail::ATTACHMENT_NAME[attachment]);
		} else {
			prompt_plain("\n" + dialog::info::MAIL_ATTACHED_PLUGIN + dialog::mail::ATTACHMENT_PLUGIN_NAME[attachment - 100]);
		}
	}
}

std::string mail::get_time() {
	// Get current time
	time_t t = time(0);
	struct tm * now = new tm();
	localtime_s(now, &t);
	std::string ret = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday) + " " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min + 1) + ":" + std::to_string(now->tm_sec + 1);
	return ret;
}

void mail::refresh_detail() {
	std::string str;
	str = "<Delivered to> " + recipient + "\n<Sent from> " + sender + "\n<At> " + current_time + "\n<Status> Delivered" + "\n<Spam Filtered> False\n<Spam Recognized>\n<Attachment ID> " + std::to_string(get_attachment());
	detail->set_desc(str);
}

/*	*	*	*	*	*	PUBLIC FUNCTION		*	*	*	*	*	*/

bool mail::set_attachment(int value) {
	// Test value validity
	if (value < 0) {
		prompt_debug(dialog::debug::INVALID_MAIL_ATTACHMENT_INDEX);
		return false;
	} else if (!is_valid_attachment(value)) {
		return false;
	} else {
		attachment = value;
		if (value == 0)
			this->remove_cmd("transmit");
		else
			this->add_cmd("transmit", transmit);
	}
	this->refresh_detail();
	return true;
}