/*
	game_core.cpp

	Created on 052314
	Author: Anoxic
	*/


#include "stdafx.h"

#include <string>
#include <utility>
#include <Windows.h>

#include "account.h"
#include "chatroom.h"
#include "command_catalog.h"
#include "game_core.h"
#include "inbox.h"
#include "menu.h"
#include "outbox.h"
#include "plugin.h"
#include "surveilant.h"
#include "sys.h"
#include "task_menu.h"
#include "tracker.h"

// xxx yet to be defined
const int game_core::MAX_LEVEL = 46;
const int game_core::SLEEP_DELAY = 300;

/*	*	*	*	*	*	PRIVATE FUNCTIONS	*	*	*	*	*	*/

void game_core::act() {
	switch (level) {
		case -1:
			if (current == main_menu) {
				develop_at(level);
				++level;
			}
			break;
		case 0:
			// Letters read
			if (current == main_inbox->find_cmd("001")->second) {
				// Test if the attachment has been transmitted
				if (((mail*) current)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 1:
			if (current == (Mino->find_cmd("outbox")->second)->find_cmd("001")->second) {
				// Mail retrieved
				if (((mail*) current)->is_retrieved()) {
					inc_level();
				}
			}
			break;
		case 2:
			if (current == (Mino->find_cmd("inbox")->second)->find_cmd("001")->second) {
				// Mail replied
				if (((mail*) current)->is_replied()) {
					inc_level();
				}
			}
			break;
		case 3:
			if (current == Mino) {
				inc_level();
			}
			break;
		case 4:
			// New mail read
			if (current == main_inbox->find_cmd("002")->second) {
				inc_level();
			}
			break;
		case 5:
			// New mail read
			if (current == Mino->find_cmd("inbox")->second->find_cmd("002")->second) {
				// Test if plugin has been transmitted
				if (((mail*) current)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 6:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("001")->second) {
				inc_level();
			}
			break;
		case 7:
			// New mail read
			if (current == Mino->find_cmd("inbox")->second->find_cmd("003")->second) {
				inc_level();
			}
			break;
		case 8:
			if (current == main_menu) {
				// Fizz's account locked
				if (Split->get_desc() == dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_LOCKED) {
					inc_level();
				}
			}
			break;
		case 9:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("002")->second) {
				inc_level();
			}
			break;
		case 10:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("003")->second) {
				if (((mail*) current)->get_attachment() == 0) {
					// Plugin transmitted
					inc_level();
				}
			}
			break;
		case 11:
			// Chatroom entered
			if (current == chat) {
				// Chat joined
				if (((chatroom*) chat)->get_status() == 1) {
					inc_level();
				}
			}
			break;
		case 12:
			// New mail read
			if (current == main_inbox->find_cmd("003")->second) {
				inc_level();
			}
			break;
		case 13:
			// New mail read
			if (current == Mino->find_cmd("inbox")->second->find_cmd("004")->second) {
				if (((mail*) current)->get_attachment() == 0) {
					// Plugin transmitted
					inc_level();
				}
			}
			break;
		case 14:
			// New mail replied
			if (current == Mino->find_cmd("inbox")->second->find_cmd("004")->second) {
				if (((mail*) current)->is_replied()) {
					inc_level();
				}
			}
			break;
		case 15:
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("004")->second) {
				inc_level();
			}
			break;
		case 16:
			// Make sure that the player has completed quit the maco system
			if (current == main_menu) {
				// File transmitted
				if (((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("004")->second)->get_attachment() == 0)
					inc_level();
			}
			break;
		case 17:
			// New password matched
			if (current == Foxtrot) {
				inc_level();
			}
			break;
		case 18:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("005")->second) {
				inc_level();
			}
			break;
		case 19:
			// New mail read
			if (current == main_inbox->find_cmd("004")->second) {
				inc_level();
			}
			break;
		case 20:
			// Attachment transmitted
			if (current == Split->find_cmd("inbox")->second->find_cmd("007")->second) {
				if (((mail*) current)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 21:
		case 23:
			if (current == surveil) {
				// Surveillance system disabled
				if (((surveilant*) current)->is_locked()) {
					inc_level();
				}
			}
			break;
		case 22:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("006")->second) {
				inc_level();
			}
			break;
			// case 23: See above "case 21"
		case 24:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("007")->second) {
				inc_level();
			}
			break;
		case 25:
			// User must not be at Jason's account
			if (current == Foxtrot) {
				// Test if surveillance system has been locked
				if (((surveilant*) surveil)->is_locked()) {
					inc_level();
				}
			}
			break;
		case 26:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second) {
				inc_level();
			}
			break;
		case 27:
			// Outbox entered - avoid "immediate" reply
			if (current == Mino->find_cmd("outbox")->second) {
				// Mail replied
				if (((mail*) Mino->find_cmd("inbox")->second->find_cmd("004")->second)->is_replied()) {
					inc_level();
				}
			}
			break;
		case 28:
			// New mail read
			if (current == Mino->find_cmd("inbox")->second->find_cmd("005")->second) {
				inc_level();
			}
			break;
		case 29:
			// Mail to be replied read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second) {
				// Test if the mail has been replied
				if (((mail*) current)->is_replied()) {
					inc_level();
				}
			}
			break;
		case 30:
			// New mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("009")->second) {
				if (((mail*) current)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 31:
			// Test if MIA has been entered
			if (current == mia) {
				if (((task_menu*) mia)->is_accomplished()) {
					// Objective accepted
					inc_level();
				}
			}
			break;
		case 32:
			// Mail replied
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("009")->second) {
				if (((mail*) current)->is_replied()) {
					inc_level();
				}
			}
			break;
		case 33:
			// Mail read
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("010")->second) {
				inc_level();
			}
			break;
		case 34:
			// Mail attachment downloaded
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("011")->second) {
				if (((mail*) current)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 35:
			// Mail read
			if (current == Bandit->find_cmd("inbox")->second->find_cmd("001")->second) {
				inc_level();
			}
			break;
		case 36:
			// Mail read
			if (current == main_inbox->find_cmd("005")->second) {
				inc_level();
			}
			break;
		case 37:
			// "Changed" user logged in
			if (current == Foxtrot) {
				inc_level();
			}
			break;
		case 38:
			// Mail read
			if (current == main_inbox->find_cmd("006")->second) {
				inc_level();
			}
			break;
		case 39:
			// Re-read one old mail
			if (current == Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second) {
				inc_level();
			}
			break;
		case 40:
			// Mail read
			if (current == main_inbox->find_cmd("007")->second) {
				inc_level();
			}
			break;
		case 41:
			// Objective completed
			if (current == Foxtrot) {
				if (!current->has_cmd("submit")) {
					// Menu removed: completed
					inc_level();
				}
			}
			break;
		case 42:
			// Mail read
			if (current == Mino->find_cmd("inbox")->second->find_cmd("006")->second) {
				inc_level();
			}
			break;
		case 43:
			// Mail read
			if (current == Jason->find_cmd("inbox")->second->find_cmd("002")->second) {
				// Plugin transmitted
				if (((mail*) Mino->find_cmd("inbox")->second->find_cmd("007")->second)->get_attachment() == 0) {
					inc_level();
				}
			}
			break;
		case 44:
			// Clyde's account hacked
			if (current == Clyde) {
				inc_level();
			}
			break;
		case 45:
			// Mail read
			if (current == Clyde->find_cmd("outbox")->second->find_cmd("002")->second) {
				inc_level();
			}
			break;
		case 46:
			// The entire story read
			if (current == story_line) {
				// Print the entire story
				bool flag = util::print_file(dialog::story::STORY_FILENAME, ((tracker*) story_line)->get_all_story() + dialog::story::STORY[46]);
				if (flag)
					inc_level();
				else
					prompt_abortion(dialog::abortion::FILE_STREAM_ERROR);
			}
		default:
			break;
	}
}

void game_core::develop_at(int lev) {
	switch (lev) {
		case -1:
			((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[0]);
			// Detail modify
			((mail*) main_inbox->find_cmd("001")->second)->set_recipient(dialog::info::ADDRESS_MAIN);
			// Hide Pluto's address
			((mail*) main_inbox->find_cmd("001")->second)->set_sender(dialog::info::ADDRESS_UNDEFINED);
			((mail*) main_inbox->find_cmd("001")->second)->remove_reply();
			((mail*) main_inbox->find_cmd("001")->second)->set_attachment(100);
			break;
		case 0: {
			// Plugin added
			((plugin*) extension)->add_plugin("705F5");
			// COMM system access granted
			main_menu->add_cmd("comm", comm);
			// User account added
			comm->add_cmd("Mino", Mino);
			// User password initialized
			comm->add_para("Mino", "password");
			// Find the outbox of Mino
			menu* mino_outbox = Mino->find_cmd("outbox")->second;
			// Generate the resignation letter
			menu* new_mail = ((outbox*) mino_outbox)->generate_mail("Fizz", dialog::mail::CONTENTS[1], "Mino");
			((outbox*) mino_outbox)->interact(new_mail);
			// Enable retrieve
			((mail*) new_mail)->enable_retrieve();
			break;
		}
		case 1: {
			// Add new user without para added
			comm->add_cmd("Fizz", Fizz);
			// Set denied access to this account
			Fizz->set_desc(dialog::abortion::ACCOUNT_ACCESS_DENIED_HEADER + dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN);
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[2]);
			// Find the mail Mino has just received
			menu* new_mail = Mino->find_cmd("inbox")->second->find_cmd("001")->second;
			// Enable reply 
			((mail*) new_mail)->enable_reply();
			break;
		}
		case 2: {
			// Send letter
			((account*) Mino)->send("Fizz", dialog::mail::CONTENTS[3]);
			// Set mail read for Fizz
			((mail*) Fizz->find_cmd("inbox")->second->find_cmd("001")->second)->set_read(true);
			break;
		}
		case 3: {
			// Receive a letter from Pluto
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[4]);
			// Detail modify
			((mail*) new_mail)->set_recipient(dialog::info::ADDRESS_MAIN);
			// Hide Pluto's address
			((mail*) new_mail)->set_sender(dialog::info::ADDRESS_UNDEFINED);
			// Reply disabled
			((mail*) new_mail)->remove_reply();
			break;
		}
		case 4: {
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[5]);
			// Plugin attached
			((mail*) Mino->find_cmd("inbox")->second->find_cmd("002")->second)->set_attachment(102);
			break;
		}
		case 5: {
			// Plugin added
			((plugin*) extension)->add_plugin("964B8");
			// MACO system added
			main_menu->add_cmd("maco", maco);
			// User account added
			maco->add_cmd("Foxtrot", Foxtrot);
			maco->add_cmd("Split", Split);
			// Access granted for Foxtrot
			maco->add_para("Foxtrot", "password");
			// Set denied access to Split
			Split->set_desc(dialog::abortion::ACCOUNT_ACCESS_DENIED_HEADER + dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN);
			// Welcome mail
			((account*) Split)->send("Foxtrot", dialog::mail::CONTENTS[6]);
			break;
		}
		case 6: {
			// Feedback from Fizz
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[7]);
			break;
		}
		case 7: {
			// Empty password means this account can never be accessed by blind guess
			maco->add_para("Split", "");
			((account*) Split)->set_reset_lim(5);
			// Empty reset_password to make the account locked
			((account*) Split)->set_reset_password("");
			break;
		}
		case 8: {
			// New character appears
			maco->add_cmd("Echo", Echo);
			((account*) Echo)->send("Foxtrot", dialog::mail::CONTENTS[8]);
			break;
		}
		case 9: {
			Split->set_desc(dialog::abortion::ACCOUNT_ACCESS_DENIED_HEADER + dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN);
			((account*) Split)->send("Foxtrot", dialog::mail::CONTENTS[9]);
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("003")->second)->set_attachment(104);
			break;
		}
		case 10: {
			// Plugin added
			((plugin*) extension)->add_plugin("964C9");
			Foxtrot->add_cmd("chat", chat);
			break;
		}
		case 11: {
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[10]);
			// Detail modify
			((mail*) new_mail)->set_recipient(dialog::info::ADDRESS_MAIN);
			// Hide Pluto's address
			((mail*) new_mail)->set_sender(dialog::info::ADDRESS_UNDEFINED);
			// Remove reply
			((mail*) new_mail)->remove_reply();
			break;
		}
		case 12: {
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[11]);
			((mail*) Mino->find_cmd("inbox")->second->find_cmd("004")->second)->set_attachment(103);
			break;
		}
		case 13: {
			// Plugin added
			((plugin*) extension)->add_plugin("964B9");
			((mail*) (Mino->find_cmd("inbox")->second->find_cmd("004")->second))->enable_reply();
			break;
		}
		case 14: {
			((account*) Mino)->send("Fizz", dialog::mail::CONTENTS[12]);
			((mail*) Fizz->find_cmd("inbox")->second->find_cmd("002")->second)->set_read(true);
			// New account added
			maco->add_cmd("Tyler", Tyler);
			// Set denied access to this account
			Tyler->set_desc(dialog::abortion::ACCOUNT_ACCESS_DENIED_HEADER + dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN);
			((account*) Tyler)->send("Foxtrot", dialog::mail::CONTENTS[13]);
			((mail*) (Foxtrot->find_cmd("inbox")->second->find_cmd("004")->second))->set_attachment(1);
			break;
		}
		case 15: {
			// Do nothing
			break;
		}
		case 16: {
			// Change password
			maco->remove_para("Foxtrot");
			maco->add_para("Foxtrot", "2E9D55C");
			break;
		}
		case 17: {
			((account*) Tyler)->send("Foxtrot", dialog::mail::CONTENTS[14]);
			break;
		}
		case 18: {
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[15]);
			// Detail modify
			((mail*) new_mail)->set_recipient(dialog::info::ADDRESS_MAIN);
			// Hide Pluto's address
			((mail*) new_mail)->set_sender(dialog::info::ADDRESS_UNDEFINED);
			// Disable reply
			((mail*) new_mail)->remove_reply();
			// Plugin attached
			((mail*) new_mail)->set_attachment(105);
			break;
		}
		case 19: {
			// Plugin added
			((plugin*) extension)->add_plugin("2D0BE");
			// New user to hack!
			maco->add_cmd("Jason", Jason);
			// Set denied access to Jason
			Jason->set_desc(dialog::abortion::ACCOUNT_ACCESS_DENIED_HEADER + dialog::abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN);
			// Split is now accessible
			maco->add_para("Split", "1106");
			// Remove denied access description
			Split->set_desc("");
			// Receive junk mails
			std::vector<std::string>::const_iterator it1, it2, it3;
			it1 = dialog::mail::SPAM.begin();
			it2 = dialog::mail::SPAM_SENDER.begin();
			it3 = dialog::mail::SPAM_ADDRESS.begin();
			for (; it1 != dialog::mail::SPAM.end(); ++it1, ++it2) {
				menu* new_mail = ((inbox*) Split->find_cmd("inbox")->second)->interact(*it2, *it1);
				// Modify the mail address of sender
				((mail*) new_mail)->set_sender(*it3);
			}
			// Send letter to Split
			((account*) Jason)->send("Split", dialog::mail::CONTENTS[16]);
			// Set attachment
			((mail*) Split->find_cmd("inbox")->second->find_cmd("007")->second)->set_attachment(2);
			break;
		}
		case 20: {
			// Jason is now accessible
			maco->add_para("Jason", "20140407");
			// Remove denied access description
			Jason->set_desc("");
			Jason->add_cmd("surveil", surveil);
			break;
		}
		case 21: {
			((account*) Echo)->send("Foxtrot", dialog::mail::CONTENTS[17]);
			break;
		}
		case 22: {
			// Reset surveillance system
			((surveilant*) surveil)->unlock(false);
			((surveilant*) surveil)->add_disable_ID(dialog::story::ID_ECHO);
			break;
		}
		case 23: {
			((account*) Echo)->send("Foxtrot", dialog::mail::CONTENTS[18]);
			break;
		}
		case 24: {
			// Reset surveillance system
			((surveilant*) surveil)->unlock();
			((surveilant*) surveil)->remove_disable_ID(dialog::story::ID_ECHO);
			((surveilant*) surveil)->add_enable_ID(dialog::story::ID_FOXTROT);
			break;
		}
		case 25: {
			((account*) Jason)->send("Foxtrot", dialog::mail::CONTENTS[19]);
			break;
		}
		case 26: {
			// Change detail of the letter for later plot
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second)->set_recipient("alpha@matic.org, bravo@matic.org, charlie@matic.org, delta@matic.org, echo@matic.org, foxtrot@matic.org");
			// Enable reply for one selected mail from Fizz
			((mail*) Mino->find_cmd("inbox")->second->find_cmd("004")->second)->enable_reply();
			break;
		}
		case 27: {
			((account*) Mino)->send("Fizz", dialog::mail::CONTENTS[20]);
			((mail*) Fizz->find_cmd("inbox")->second->find_cmd("003")->second)->set_read(true);
			// "immediate" reply
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[21]);
			// Enable reply for the letter Jason just sent
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second)->enable_reply();
			break;
		}
		case 28: {
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("008")->second)->enable_reply();
			break;
		}
		case 29: {
			// Reply to the mail
			((account*) Foxtrot)->send("Jason", dialog::mail::CONTENTS[22]);
			// "immediate" reply
			((account*) Jason)->send("Foxtrot", dialog::mail::CONTENTS[23]);
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("009")->second)->set_attachment(106);
			break;
		}
		case 30: {
			// Plugin added
			((plugin*) extension)->add_plugin("4D28E");
			Foxtrot->add_cmd("mia", mia);
			break;
		}
		case 31: {
			// New user added
			comm->add_cmd("Bandit", Bandit);
			comm->add_para("Bandit", "9350422");
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("009")->second)->enable_reply();
			break;
		}
		case 32: {
			// Reply to the mail
			((outbox*) Foxtrot->find_cmd("outbox")->second)->interact("Jason", dialog::mail::CONTENTS[24]);
			// Sending mail unsuccessfully
			((account*) Foxtrot)->receive("MACO System Group", dialog::mail::CONTENTS[25]);
			break;
		}
		case 33: {
			// Explanatory mail from Echo
			((account*) Echo)->send("Foxtrot", dialog::mail::CONTENTS[26]);
			((mail*) Foxtrot->find_cmd("inbox")->second->find_cmd("011")->second)->set_attachment(107);
			break;
		}
		case 34: {
			// Plugin added
			((plugin*) extension)->add_plugin("14FC6");
			// Faked ID approved at this moment
			Bandit->set_access_ID("14FC6");
			((account*) Bandit)->receive("the Department of Human Resource", dialog::mail::CONTENTS[27]);
			// Set mail as read
			((mail*) Bandit->find_cmd("inbox")->second->find_cmd("001")->second)->set_read(true);
			break;
		}
		case 35: {
			// Pluto's late-arrived mail
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[28]);
			pluto_blur((mail*) new_mail);
			break;
		}
		case 36: {
			// Retrieve COMM access
			main_menu->remove_cmd("comm");
			main_menu->remove_cmd("plugin");
			// Retrieve other account access in MACO
			maco->remove_para("Split");
			maco->remove_para("Jason");
			/* Origianal password
			 Split: 1106
			 Jason: 20140407
			 */
			// "Change" user
			Foxtrot->set_info(Echo->get_info());
			Foxtrot->set_desc(dialog::info::SURVEILANT_UNDER_CONTROL_STATUS);
			break;
		}
		case 37: {
			// Pluto's aplogizing letter
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[29]);
			pluto_blur((mail*) new_mail);
			break;
		}
		case 38: {
			// Do nothing
			break;
		}
		case 39: {
			// Pluto's explanative letter
			menu* new_mail = ((inbox*) main_inbox)->interact("Pluto", dialog::mail::CONTENTS[30]);
			pluto_blur((mail*) new_mail);
			break;
		}
		case 40: {
			// Generate a new mail with recipient modified
			menu* new_mail = ((inbox*) Foxtrot->find_cmd("inbox")->second)->generate_mail("Jason", dialog::mail::CONTENTS[31], "Echo");
			// Set attachment
			((mail*) new_mail)->set_attachment(3);
			((inbox*) Foxtrot->find_cmd("inbox")->second)->interact(new_mail);
			// Add new menu command
			Foxtrot->add_cmd("submit", submit);
			break;
		}
		case 41: {
			// Recover
			main_menu->add_cmd("comm", comm);
			main_menu->add_cmd("plugin", extension);
			Foxtrot->set_desc(dialog::info::ACCOUNT_HEADER + "Foxtrot");
			// Chagne access permission
			maco->set_access_ID("84A78");
			// Removing illegible plugin
			((plugin*) extension)->remove_plugin("14FC6");
			// Send exciting letter
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[32]);
			break;
		}
		case 42: {
			// Send another letter
			((account*) Fizz)->send("Mino", dialog::mail::CONTENTS[33]);
			// New plugin
			((mail*) Mino->find_cmd("inbox")->second->find_cmd("007")->second)->set_attachment(108);
			// Tricky!
			maco->add_para("Split", "6011");
			maco->add_para("Jason", "20140407");
			((account*) Clyde)->send("Jason", dialog::mail::CONTENTS[34]);
			// Set mail as read
			((mail*) Jason->find_cmd("inbox")->second->find_cmd("001")->second)->set_read(true);
			break;
		}
		case 43: {
			// Plugin added
			((plugin*) extension)->add_plugin("84A78");
			// Initiailize account detail and reset questions for Clyde
			Clyde->add_para(dialog::story::CLYDE_QUESTION[0], dialog::story::CLYDE_ANSWER[0]);
			Clyde->add_para(dialog::story::CLYDE_QUESTION[1], dialog::story::CLYDE_ANSWER[1]);
			((account*) Clyde)->set_reset_lim(3);
			((account*) Clyde)->set_reset_password("password");
			maco->add_cmd("Clyde", Clyde);
			// I don't believe anyone can guess this out lol :)
			maco->add_para("Clyde", "c4rycn8o7cynofcyno8q2cyry7q2noo3r7qc2rcnyq32r327");
			((outbox*) Clyde->find_cmd("outbox")->second)->interact("Van", dialog::mail::CONTENTS[35]);
			// Add reset limit
			((account*) Clyde)->set_reset_lim(3);
			break;
		}
		case 44:
		case 45:
		case 46:
			// Do nothing
			break;
		default:
			break;
	}
}

void game_core::inc_level() {
	prompt_info(dialog::info::LEVEL_UP);
	develop_at(level);
	// Refresh the tracker after level is incremented
	((tracker*) story_line)->refresh();
	++level;
}

void game_core::init() {
	level = -1;

	main_menu = new menu("Mino");
	main_menu->set_info(dialog::info::ADAPTER_HEADER);
	main_menu->set_desc(dialog::info::ADAPTER_STATUS);
	extension = new plugin(main_menu);
	main_inbox = new inbox(main_menu, "Inbox");
	main_outbox = new outbox(main_menu, "Outbox");
	story_line = new tracker(main_menu, level);
	((tracker*) story_line)->refresh();

	comm = new sys(main_menu, "COMM");
	comm->set_access_ID("705F5");
	((sys*) comm)->set_mail_address("@tak.org");
	maco = new sys(main_menu, "MACO");
	maco->set_access_ID("964B8");
	((sys*) maco)->set_mail_address("@matic.org");

	Alpha = new account(maco, "Alpha", "Alpha");
	Bandit = new account(comm, "Bandit", "Bandit");
	Bandit->set_access_ID("705F6");
	Clyde = new account(maco, "Clyde", "Clyde");
	Echo = new account(maco, "Echo", "Echo");
	Fizz = new account(comm, "Fizz", "Fizz");
	Foxtrot = new account(maco, "Foxtrot", "Foxtrot");
	Foxtrot->set_access_ID("964B8");
	Jason = new account(maco, "Jason", "Jason");
	Jason->set_access_ID("964B9");
	Mino = new account(comm, "Mino", "Mino");
	Mino->set_access_ID("705F5");
	// Easter-egg!
	Pluto = new account(comm, "Anoxic", "Pluto");
	Split = new account(maco, "Split", "Split");
	Split->set_access_ID("964B9");
	Tyler = new account(maco, "Tyler", "Tyler");

	chat = new chatroom(Foxtrot);
	chat->set_access_ID("964C9");
	submit = new menu(Foxtrot, "Submit");
	surveil = new surveilant(Jason, "Surveillant");
	surveil->set_access_ID("2D0BE");
	mia = new task_menu(Foxtrot, "MIA");

	main_menu->add_cmd("inbox", main_inbox);
	main_menu->add_cmd("outbox", main_outbox);
	main_menu->add_cmd("plugin", extension);
	main_menu->add_cmd("story", story_line);

	// Easter egg added!
	comm->add_cmd("Anoxic", Pluto);
	comm->add_para("Anoxic", "password");
	Pluto->set_desc("AH-o, You have find something really amazing! Contact me for reward :P");
	((inbox*) Pluto->find_cmd("inbox")->second)->interact("Anoxic", "My email address is guanrunjie@gmail.com! This is my first game anyway. Thanks for support!");
}

void game_core::intro() {
	prompt_plain(dialog::story::INTRO.at(0));
	std::string ret;
	while ((ret = prompt_input()) != "next") {
		if (DEBUG_MODE) {
			// Debug use only
			// *******************FROM HERE**************************
			if (ret == "skip")
				return;
			else {
				// Convert to int
				int value = atoi(ret.c_str());
				this->advance_to(value);
				((plugin*) extension)->install_all();
				return;
			}
			// *******************TO HERE****************************
		}
		prompt_abortion(ret + " : " + dialog::abortion::INVALID_COMMAND);
	}
	prompt_plain(dialog::story::INTRO[1]);
	while (true) {
		ret = prompt_input();
		std::pair<std::string, std::string> split = this->split(ret);
		if (split.first != "next")
			prompt_abortion(ret + " : " + dialog::abortion::INVALID_COMMAND);
		else if (split.second != "paragraph")
			prompt_abortion(split.second + " : " + dialog::abortion::INVALID_PARAMETER + " for next");
		else
			break;
	}
	prompt_plain(dialog::story::INTRO[2]);
	while ((ret = prompt_input()) != "next")
		prompt_abortion(ret + " : " + dialog::abortion::INVALID_COMMAND);
	prompt_plain(dialog::story::INTRO[3]);
	while ((ret = prompt_input()) != "start") {
		if (ret == "?") {
			command_catalog cc;
			prompt_info(dialog::info::HELP_FILE_HEADER);
			prompt_plain("?\t" + cc["?"]);
			prompt_plain("start\t" + cc["start"]);
		} else
			prompt_abortion(ret + " : " + dialog::abortion::INVALID_COMMAND);
	}
	prompt_plain(dialog::story::INTRO[4]);
	// Input any words
	prompt_input();
	prompt_separator();
	prompt_plain(dialog::story::WELCOME);
}

void game_core::outro() {
	// Iterate to display the outro info
	for (std::vector<std::string>::const_iterator it = dialog::story::OUTRO.begin(); it != dialog::story::OUTRO.end(); ++it) {
		prompt_plain(*it);
		// Press any key to continue
		prompt_input(dialog::info::ANY_KEY_CONTINUE);
	}
}

std::pair<std::string, std::string> game_core::split(const std::string& str) {
	std::string::size_type index = str.find_first_of(' ');
	if (index == str.npos)
		// space not found
		return std::make_pair(str, "");
	else
		// space found
		return std::make_pair(str.substr(0, index), str.substr(index + 1));
}

void game_core::pluto_blur(menu* new_mail) {
	// Detail modify
	((mail*) new_mail)->set_recipient(dialog::info::ADDRESS_MAIN);
	// Hide Pluto's address
	((mail*) new_mail)->set_sender(dialog::info::ADDRESS_UNDEFINED);
	// Remove reply
	((mail*) new_mail)->remove_reply();
}

/*	*	*	*	*	*	PUBLIC FUNCTIONS	*	*	*	*	*	*/

game_core::~game_core() {
	// Main menu(s)
	delete main_menu;
	delete extension;
	delete main_inbox;
	delete main_outbox;
	delete story_line;
	// System
	delete comm;
	delete maco;
	// Account
	delete Alpha;
	delete Bandit;
	delete Clyde;
	delete Echo;
	delete Fizz;
	delete Foxtrot;
	delete Jason;
	delete Mino;
	delete Pluto;
	delete Split;
	delete Tyler;
	// Utility
	delete chat;
	delete surveil;
	delete mia;
}

bool game_core::authenticate(menu* entering) {
	std::string ID = entering->get_access_ID();
	if (ID != "") {
		// Plugin needed
		if (((plugin*) extension)->is_installed(ID)) {
			// Plugin installed
			return true;
		} else {
			prompt_abortion(dialog::abortion::PLUGIN_MISSING + ID);
			return false;
		}
	} else {
		return true;
	}
}

void game_core::advance_to(int lev) {
	if (lev < -1 || lev > MAX_LEVEL) {
		prompt_debug(dialog::debug::LEVEL_INDEX_OUT_OF_BOUND);
	} else if (lev == -1) {
		// Do nothing
	} else {
		// Because the situation is differnt if level == -1
		if (level == -1) {
			develop_at(-1);
			++level;
		}
		for (int i = level; i != lev + 1; ++i)
			inc_level();

	}
}

void game_core::start_game() {
	this->intro();
	current = main_menu;
	while (level <= MAX_LEVEL) {
		// Make it real for server communication
		this->act();
		prompt_separator();
		prompt_plain("\n");
		std::string ret_str = prompt_input(current->get_dir());
		std::pair<std::string, std::string> split = this->split(ret_str);
		Sleep(SLEEP_DELAY);
		menu* tmp = current->enter(split.first, split.second);
		// Authentiacte plugin
		if (authenticate(tmp))
			current = tmp;
	}
	this->outro();
}
