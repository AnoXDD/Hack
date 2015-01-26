/*
 * dialog.h
 * This class contains important text files and other utilities of this game
 *  Created on: Mar 17, 2014
 *      Author: Ano
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include <string>
#include <utility>
#include <vector>

namespace dialog {
	/* Control the command print */
	class print_control {
	public:
		/* If true, no input related to cmd_line_val will be print, thus cmd_line_val stops counting */
		static bool silent_print;
	};
	class counter {
		/* Count how many lines of abortions/warning/info/plain, etc. have been displayed */
		static int cmd_line_val;
	public:
		/* Return current formatted cmd_line_val
		 Each return will add cmd_line_val by one 
		 */
		static std::string get_line_val() {
			return "{" + std::to_string(cmd_line_val++) + "}\t";
		}
		static void set_cmd_line_val(const int& val) {
			cmd_line_val = val;
		}
	};

	class warning {
	public:
		const static std::string INVALID_EMPTY_STRING;
		const static std::string PASSWORD_LIMIT_REACHED;
	};

	class abortion {
	public:
		// Error type(s) following the header
		const static std::string ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN;
		const static std::string ACCOUNT_ACCESS_DENIED_ERROR_LOCKED;
		// The use of this abortion string must be followed by a error type above
		const static std::string ACCOUNT_ACCESS_DENIED_HEADER;
		const static std::string ANSWER_MATCHED;
		const static std::string ANSWER_MISMATCHED;
		const static std::string FILE_STREAM_ERROR;
		const static std::string INVALID_COMMAND;
		const static std::string INVALID_PARAMETER;
		const static std::string LOAD_GAME_FAILED;
		const static std::string MAIL_ATTACHMENT_DOWNLOAD_FAILED;
		const static std::string MISSING_PARAMETERS;
		const static std::string PLUGIN_INVALID_PARAMETER;
		const static std::string PLUGIN_MISSING;
		const static std::string PLUGIN_MISSING_PARAMETER;
		const static std::string RETURN_NOT_ALLOWED;
		const static std::string SURVEILANT_ENABLING_FAILED;
		const static std::string SURVEILANT_INVALID_PARAMETERS;
		const static std::string SURVEILANT_THROTTLED;
		const static std::string SURVEILANT_MISSING_PARAMETERS;
		const static std::string TASK_INVALID_PARAMETERS_ID;
		const static std::string TASK_INVALID_PARAMETERS_SUBMISSION;
		const static std::string TASK_MISSING_PARAMETERS;
		const static std::string TASK_SUBMISSION_INCORRECT;
		const static std::string UNNECESSARY_PARAMETERS;
		const static std::string USERNAME_AND_PASSWORD_MISMATCHED;
	};

	class info {
	public:
		const static std::string ACCOUNT_HEADER;
		const static std::string ARCHIVE_FILE_NAME;
		const static std::string ARCHIVE_FILE_NAME_DEBUG;
		const static std::string ADAPTER_HEADER;
		const static std::string ADAPTER_STATUS;
		const static std::string ADDRESS_MAIN;
		const static std::string ADDRESS_UNDEFINED;
		const static std::string ANSWER_MATCHED;
		const static std::string ANY_KEY_CONTINUE;
		const static std::string AUTHENTICATION_PASSED;
		const static std::string AUTHENTICATION_REQUIRED;
		const static std::string CHATROOM_ACCESS_DENIED;
		const static std::string CHATROOM_DISPLAY_HISTORY;
		const static std::string CHATROOM_NO_HISTORY;
		const static std::string CHATROOM_WELCOME;
		const static std::string HELP_FILE_HEADER;
		const static std::string LEVEL_DISPLAY;
		const static std::string LEVEL_UP;
		const static std::string LOAD_GAME_ABORT_CONFIRM;
		const static std::string LOAD_GAME_PROCESSING;
		const static std::string LOAD_GAME_PROMPT;
		const static std::string LOAD_GAME_SUCCESS;
		const static std::string MAIL_ATTACHED;
		const static std::string MAIL_ATTACHED_PLUGIN;
		const static std::string MAIL_ATTACHMENT_TRANSMITTED;
		const static std::string MAIL_ATTACHMENT_TRANSMITTING;
		const static std::string MAIL_HEADER;
		const static std::string MAIL_REPLIED;
		const static std::string MAIL_REPLY_DISABLED;
		const static std::string MAIL_REPLY_ENABLED;
		const static std::string MAIL_RETRIEVAL_DISABLED;
		const static std::string MAIL_RETRIEVAL_ENABLED;
		const static std::string MAIL_RETRIEVED;
		const static std::string MAIL_SET_AS_UNREAD;
		const static std::string MAILBOX_ALL_MAILS_SENT;
		const static std::string MAILBOX_IN_HEADER;
		const static std::string MAILBOX_MAIL_SENDING;
		const static std::string MAILBOX_NEW_MAILS_1;
		const static std::string MAILBOX_NEW_MAILS_2;
		const static std::string MAILBOX_NEW_SINGLE_MAIL;
		const static std::string MAILBOX_NO_NEW_MAILS;
		const static std::string MAILBOX_OUT_HEADER;
		const static std::string MAILBOX_PREVIEW_NA;
		const static std::string MAILBOX_REFRESHING;
		const static std::string PASSWORD_RESET_FAILED;
		const static std::string PASSWORD_RESET_SUCCESS;
		const static std::string PLUGIN_EMPTY;
		const static std::string PLUGIN_HEADER;
		const static std::string PLUGIN_INSTALLED;
		const static std::string PLUGIN_INSTALLING;
		const static std::string PLUGIN_INSTALLING_SUCCESSFUL;
		const static std::string PLUGIN_UNINSTALLED;
		const static std::string PLUGIN_UNINSTALLING;
		const static std::string PLUGIN_UNINSTALLING_SUCCESSFUL;
		const static std::string QUESTIONS_AUTHENTICATION;
		const static std::string QUESTIONS_AUTHENTICATION_PASSED;
		const static std::string RETURN_TO_PREVIOUS;
		const static std::string STORY_ALL_ENDER;
		const static std::string SURVEILANT_DISABLE_CONFIRM;
		const static std::string SURVEILANT_DISABLED;
		const static std::string SURVEILANT_DISABLING;
		const static std::string SURVEILANT_DISABLING_SUCCESSFUL;
		const static std::string SURVEILANT_ENABLED;
		const static std::string SURVEILANT_ENABLING;
		const static std::string SURVEILANT_ENABLING_SUCCESSFUL;
		const static std::string SURVEILANT_HEADER;
		const static std::string SURVEILANT_LOG_HEADER;
		const static std::string SURVEILANT_STATUS_DISABLED;
		const static std::string SURVEILANT_STATUS_ENABLED;
		const static std::string SURVEILANT_UNDER_CONTROL_STATUS;
		const static std::string TASK_OBJECTIVE_ACCEPTED;
		const static std::string TASK_OBJECTIVE_DISABLED;
		const static std::string TASK_OBJECTIVE_LIST;
		const static std::string TASK_OBJECTIVE_LIST_NEW;
		const static std::string TASK_OBJECTIVE_USER;
		const static std::string TASK_SUBMISSION_CORRECT;
		const static std::string TASK_SUBMISSION_HEADER_ACCOUNT;
		const static std::string TASK_SUBMISSION_HEADER_COMPLEX;
		const static std::string TASK_SUBMISSION_PIECE;
		const static std::string TASK_SUBMISSION_PENDING;
		const static std::string TASK_WELCOME;
	};

	class debug {
	public:
		const static std::string COMMAND_OR_PARAMETER_NOT_EXISTS;
		const static std::string INVALID_MAIL_ATTACHMENT_INDEX;
		const static std::string INVALID_SUBMENU_PARENT;
		const static std::string LEVEL_INDEX_OUT_OF_BOUND;
		const static std::string MAIL_USER_NOT_DEFINED;
		const static std::string MAILBOX_INDEX_OVERFLOW;
		// const static std::string PASSWORD_REQUIRED_FOR_NON_SYSTEM;
		const static std::string REPEATED_COMMAND_OR_PARAMETER;
		const static std::string SYSTEM_USER_NOT_DEFINED;
	};

	/* This class stores information about the mail */
	class mail {
		const static std::vector<std::string> CLOSING;
	public:
		const static std::vector<std::string> ATTACHMENT_NAME;
		const static std::vector<std::string> ATTACHMENT_PLUGIN_NAME;
		const static std::vector<std::string> ATTACHMENT;
		const static std::vector<std::string> CONTENTS;
		const static std::vector<std::string> SPAM;
		const static std::vector<std::string> SPAM_ADDRESS;
		const static std::vector<std::string> SPAM_SENDER;
		/* Return a random closing of a mail */
		static std::string random_closing() {
			return CLOSING[rand() % CLOSING.size()];
		}
	};

	/* This class stores information about the story line of this game */
	class story {
	public:
		/* This is the welcome header of the game */
		const static std::string WELCOME;
		/* ID numbers */
		const static std::string ID_ECHO;
		const static std::string ID_FOXTROT;
		/* Old and new log file */
		const static std::string LOG_NEW;
		const static std::string LOG_OLD;
		const static std::string STORY_FILENAME;
		// const static std::string OUTRO;

		/* This interval will be read after the content in the "chatroom" is read */
		const static std::vector<int> CHATROOM_INTERVAL;
		const static std::vector<std::string> CHATROOM;
		const static std::vector<std::string> CLYDE_ANSWER;
		const static std::vector<std::string> CLYDE_QUESTION;
		const static std::vector<std::string> INTRO;
		const static std::vector<std::string> OUTRO;
		/* The ten pieces to submit when Mino accidentally put himself as Echo */
		const static std::vector<std::string> PASSPHRASE;
		/* Each single story line should be added after the player has completed the current level */
		const static std::vector<std::string> STORY;
	};

}

namespace util {
	// Output a file, return if print succeeds
	bool print_file(const std::string& path, const std::string& content);
	// Read a file, return the string of the file, an empty string if fails
	const std::string read_file(const std::string& path);
	// Generate a random number
	int random_int();
}

void prompt_abortion(const std::string&);
void prompt_debug(const std::string&);
/*
 This function will use command_catelog to automatically find the corresponding help instruction and adjust space
 */
void prompt_help(const std::string&);
void prompt_info(const std::string&);
void prompt_plain(const std::string&);
void prompt_warning(const std::string&);

void prompt_dir(const std::string&);
void prompt_separator();

/*
 Prompt a mark to remind the player to input command
 This function MUST be attached after each prompt from system
 @Return: the user input from the first character OTHER THAN space
 */
std::string prompt_input(const std::string& str = "");

std::pair<std::string, std::string> prompt_login();

#endif /* DIALOG_H_ */
