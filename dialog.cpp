/*
 * dialog.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: Ano
 */

#include "stdafx.h"

#include <iostream>
#include <string>
#include <utility>

#include "command_catalog.h"
#include "dialog.h"

namespace dialog {
	/*	*	*	*	*	*	WARNING	*	*	*	*	*	*/
	const std::string warning::INVALID_EMPTY_STRING =
		"Invalid empty input; please try again";
	const std::string warning::PASSWORD_LIMIT_REACHED =
		"Attempt limit reached for this account; begin password resetting";

	/*	*	*	*	*	*	ABORTION	*	*	*	*	*	*/
	const std::string abortion::ACCOUNT_ACCESS_DENIED_ERROR_UNKNOWN =
		"Unknown error";
	const std::string abortion::ACCOUNT_ACCESS_DENIED_ERROR_LOCKED =
		"This account has been locked";
	const std::string abortion::ACCOUNT_ACCESS_DENIED_HEADER =
		"Access to this account denied: ";
	const std::string abortion::ANSWER_MISMATCHED =
		"Answer to this question mismatched";
	const std::string abortion::INVALID_COMMAND =
		"Cannot be recognized as a command";
	const std::string abortion::INVALID_PARAMETER =
		"Cannot be recognized as a parameter";
	const std::string abortion::MAIL_ATTACHMENT_DOWNLOAD_FAILED =
		"Mail attachment download failed. Either you have downloaded this file already or there is a file under this directory have the same name. Try to remove any unnecessary file under the game directory in your computer explorer and try again";
	const std::string abortion::MISSING_PARAMETERS =
		"Parameter required to execute this command: ";
	const std::string abortion::PLUGIN_INVALID_PARAMETER =
		"Not a valid plugin ID or not executable for this command";
	const std::string abortion::PLUGIN_MISSING =
		"Access connection destroyed: required plugin ID = ";
	const std::string abortion::PLUGIN_MISSING_PARAMETER =
		"Specify a valid plugin ID to do so";
	const std::string abortion::RETURN_NOT_ALLOWED =
		"You cannot return to previous menu";
	const std::string abortion::SURVEILANT_ENABLING_FAILED =
		"Surveillance system cannot be enabled: core file impaired";
	const std::string abortion::SURVEILANT_INVALID_PARAMETERS =
		"This is not a valid ID or does not mean \"all\"";
	const std::string abortion::SURVEILANT_MISSING_PARAMETERS =
		"Specify the ID or use \"all\" as a parameter to execute this command: ";
	const std::string abortion::SURVEILANT_THROTTLED =
		"Operation throttled! Wait for a while for next operation";
	const std::string abortion::TASK_INVALID_PARAMETERS_ID =
		"This is not a valid task ID or elevated permission required";
	const std::string abortion::TASK_INVALID_PARAMETERS_SUBMISSION =
		"This result does not pass the test from system";
	const std::string abortion::TASK_MISSING_PARAMETERS =
		"Provide sufficient details to execute this command: ";
	const std::string abortion::TASK_SUBMISSION_INCORRECT =
		"This piece of information is inconsistent with others; be advised to check the information submitted";
	const std::string abortion::UNNECESSARY_PARAMETERS =
		"Parameter not required to execute this command: ";
	const std::string abortion::USERNAME_AND_PASSWORD_MISMATCHED =
		"Account name or password mismatched";

	/*	*	*	*	*	*	INFO	*	*	*	*	*	*/
	const std::string info::ACCOUNT_HEADER =
		"Welcome, ";
	const std::string info::ADAPTER_HEADER =
		"Adapter v1.0 authorized to Mino";
	const std::string info::ADAPTER_STATUS =
		"Status: working";
	const std::string info::ADDRESS_MAIN =
		"mino@mino.me";
	const std::string info::ADDRESS_UNDEFINED =
		"#UNDEFINED#";
	const std::string info::ANSWER_MATCHED =
		"Answer to this question matched";
	const std::string info::AUTHENTICATION_PASSED =
		"Identity authenticated";
	const std::string info::AUTHENTICATION_REQUIRED =
		"Authentication required";
	const std::string info::CHATROOM_ACCESS_DENIED =
		"There is no event here at this moment";
	const std::string info::CHATROOM_DISPLAY_HISTORY =
		"Displaying your archived history...";
	const std::string info::CHATROOM_NO_HISTORY =
		"You have no history at this moment";
	const std::string info::CHATROOM_WELCOME =
		"Welcome to the chatroom, ";
	const std::string info::HELP_FILE_HEADER =
		"Displaying all available commands ...";
	const std::string info::LEVEL_DISPLAY =
		"You are now level ";
	const std::string info::LEVEL_UP =
		"Level up! You have triggered a checkpoint";
	const std::string info::MAIL_ATTACHED =
		"#ATTACHMENT#: ";
	const std::string info::MAIL_ATTACHED_PLUGIN =
		"#ATTACHMENT#: Plugin ID = ";
	const std::string info::MAIL_ATTACHMENT_TRANSMITTED =
		"Mail attachment transmitted";
	const std::string info::MAIL_ATTACHMENT_TRANSMITTING =
		"Mail attachment transmitting ...";
	const std::string info::MAIL_HEADER =
		"Displaying the entire mail...";
	const std::string info::MAIL_REPLIED =
		"You have already replied this mail";
	const std::string info::MAIL_REPLY_DISABLED =
		"You do not have to do so at this moment";
	const std::string info::MAIL_REPLY_ENABLED =
		"You have successfully replied this mail";
	const std::string info::MAIL_RETRIEVAL_DISABLED =
		"You cannot retrieve this mail because it has been successfully delievered";
	const std::string info::MAIL_RETRIEVAL_ENABLED =
		"You have successfully retrieved this mail";
	const std::string info::MAIL_RETRIEVED =
		"You have already retrieved this mail";
	const std::string info::MAIL_SET_AS_UNREAD =
		"This mail has been marked as unread";
	const std::string info::MAILBOX_ALL_MAILS_SENT =
		"All mails have been sent";
	const std::string info::MAILBOX_IN_HEADER =
		"Enter the number of letter for more information\n\tAttach.\t#.\tFrom\tContents";
	const std::string info::MAILBOX_MAIL_SENDING =
		"Some mails are still being sent ...";
	const std::string info::MAILBOX_NEW_MAILS_1 =
		"You have ";
	const std::string info::MAILBOX_NEW_MAILS_2 =
		" new mails";
	const std::string info::MAILBOX_NEW_SINGLE_MAIL =
		"You have a new mail";
	const std::string info::MAILBOX_NO_NEW_MAILS =
		"You have no new mails";
	const std::string info::MAILBOX_OUT_HEADER =
		"Enter the number of letter for more information\n\tAttach.\t#.\tTo\tContents";
	const std::string info::MAILBOX_PREVIEW_NA =
		"<PREVIEW NOT AVAIABLE>";
	const std::string info::MAILBOX_REFRESHING =
		"Mailbox has been refreshed";
	const std::string info::PASSWORD_RESET_SUCCESS =
		"Password reset successful";
	const std::string info::PASSWORD_RESET_FAILED =
		"Password reset unsuccessful";
	const std::string info::PLUGIN_EMPTY =
		"You have no available plugins for this at this moment";
	const std::string info::PLUGIN_HEADER =
		"[ID]\t[Added]\t[Description]";
	const std::string info::PLUGIN_INSTALLED =
		"This plugin has already been installed";
	const std::string info::PLUGIN_INSTALLING =
		"Installing plugin ...";
	const std::string info::PLUGIN_INSTALLING_SUCCESSFUL =
		"This plugin is installed successfully";
	const std::string info::PLUGIN_UNINSTALLED =
		"This plugin has already been uninstalled";
	const std::string info::PLUGIN_UNINSTALLING =
		"Uninstalling plugin ...";
	const std::string info::PLUGIN_UNINSTALLING_SUCCESSFUL =
		"This plugin is removed from your adapter";
	const std::string info::QUESTIONS_AUTHENTICATION =
		"Questions authentication required before reset";
	const std::string info::QUESTIONS_AUTHENTICATION_PASSED =
		"All Answers matched";
	const std::string info::RETURN_TO_PREVIOUS =
		"Returning to previous menu...";
	const std::string info::STORY_ALL_ENDER =
		"Everything that has happened so far has been displayed";
	const std::string info::SURVEILANT_DISABLE_CONFIRM =
		"Are you sure to continue? Enter \"y\" for yes or other for no: ";
	const std::string info::SURVEILANT_DISABLED =
		"Surveillance has already been disabled";
	const std::string info::SURVEILANT_DISABLING =
		"Disabling the surveillance system for ";
	const std::string info::SURVEILANT_DISABLING_SUCCESSFUL =
		"Surveillance system disable successful";
	const std::string info::SURVEILANT_ENABLED =
		"Surveillance has already been enabled";
	const std::string info::SURVEILANT_ENABLING =
		"Enabling the surveillance system for ";
	const std::string info::SURVEILANT_ENABLING_SUCCESSFUL =
		"Surveillance system enable successful";
	const std::string info::SURVEILANT_HEADER =
		"Surveilant access granted. Welcome, ";
	const std::string info::SURVEILANT_LOG_HEADER =
		"Displaying log file ...";
	const std::string info::SURVEILANT_STATUS_DISABLED =
		"Status: surveillance disabled";
	const std::string info::SURVEILANT_STATUS_ENABLED =
		"Status: surveillance enabled";
	const std::string info::SURVEILANT_UNDER_CONTROL_STATUS =
		"<NAME>\tEcho\n"
		"<ID NO.>\t07*153\n"
		"<STATUS>\tUnder Surveillance\n"
		"<EXPIRE>\tNot Available\n"
		"<OPERATOR>\tFoxtrot";
	const std::string info::TASK_OBJECTIVE_ACCEPTED =
		"You have successfully accpeted an objective (ID = 9432)";
	const std::string info::TASK_OBJECTIVE_DISABLED =
		"You cannot view the list while executing an objective";
	const std::string info::TASK_OBJECTIVE_LIST =
		"STATUS\t|NO\t|CATEGORY\t|REWARD\t|SUMMARY\n"
		"N/A\t4283\tSYS\t30\tSecurity leak\n"
		"N/A\t7539\tSYS\t20\tSecurity leak\n"
		"PENDING\t0428\tACUNT\t10\tPassword hack\n"
		"AVAIL.\t9432\tACUNT\t5\tPassword hack\n"
		"PENDING\t5839\tACUNT\t45\tUser data collection\n"
		"N/A\t8493\tMONITOR\t100\tIntercept\n"
		"PENDING\t5783\tMONITOR\t10\tMonitor behavior\n"
		"N/A\t3429\tSBOTGE\t50\tDestroy connection\n";
	const std::string info::TASK_OBJECTIVE_LIST_NEW =
		"STATUS\t|NO\t|CATEGORY\t|REWARD\t|SUMMARY\n"
		"N/A\t4283\tSYS\t30\tSecurity leak\n"
		"N/A\t7539\tSYS\t20\tSecurity leak\n"
		"PENDING\t0428\tACUNT\t10\tPassword hack\n"
		"PENDING\t5839\tACUNT\t45\tUser data collection\n"
		"N/A\t8493\tMONITOR\t100\tIntercept\n"
		"N/A\t3429\tSBOTGE\t50\tDestroy connection\n";
	const std::string info::TASK_OBJECTIVE_USER =
		"<TASK_NO>\t9432\n"
		"<CATEGORY>\tAccount\n"
		"<REWARD>\t5\n"
		"<DESCRIPTION>\n"
		"\tWe have intercepted a letter and copied its content. It is a letter from someone in charge of account information in TAK's account information, so it is a fair guess that it contains important user information. According to our previous experience, this message probably uses alliteration and letter scramble to hide the important messages. \n"
		"\tAfter you have discovered the possible account and passwords beneath it, please try to successfully log in before you submit it to us.\n"
		"\tIf we find the information submitted incorrect, you are probably subject to dismissal from this group!\n"
		"<CONTENT>\n"
		"\tFIR STLETTERI NEACHSENT ENCEAN DALL NUMB ERS. Basically the ninth list is still not complete though, and after all the things are done you will be awarded $35. Nothing is more urgent than this, despite the fact that you are on #0422. If you cannot stop procrastinating, today is your last day in this company. \n";
	const std::string info::TASK_SUBMISSION_CORRECT =
		"Congratulations! Your information passed the test from system. Wait for next available task.";
	const std::string info::TASK_SUBMISSION_HEADER_ACCOUNT =
		"Submit your cracked account information";
	const std::string info::TASK_SUBMISSION_HEADER_COMPLEX =
		"Submit your cracked information. \n"
		"There are totally 10 pieces of information, please submit their deciphered characters instead of a sentence instead one by one. Only the semicolon(;), alphabetic and numeric characters are allowed. Other illegible characters will cause your submission recognized as wrong token.\n"
		"E.g. \n"
		"[Encoded]\t|nf]fubuuxp;- \n"
		"[Decoded]\t|me]etattwo;- \n"
		"[Sentence]\tMeet at two\n"
		"[Correct submission]\tmeetattwo;\n";
	const std::string info::TASK_SUBMISSION_PIECE =
		"[Total 10] Submit your information #";
	const std::string info::TASK_SUBMISSION_PENDING =
		"Your submission is uploaded. If you do not receive any confirmation information with in next 10 seconds, consider check the validity of your submitted characters";
	const std::string info::TASK_WELCOME =
		"Welcome to the MIA! Enjoy cracking here :)";

	/*	*	*	*	*	*	DEBUG	*	*	*	*	*	*/
	const std::string debug::COMMAND_OR_PARAMETER_NOT_EXISTS =
		"This command/parameter does not exist in the map";
	const std::string debug::INVALID_MAIL_ATTACHMENT_INDEX =
		"A positive value needed for indexing the downloadable content";
	const std::string debug::INVALID_SUBMENU_PARENT =
		"The submenu's parent is not this menu";
	const std::string debug::LEVEL_INDEX_OUT_OF_BOUND =
		"Level index out of bound";
	const std::string debug::MAIL_USER_NOT_DEFINED =
		": This user does not exist to receive a letter from ";
	const std::string debug::MAILBOX_INDEX_OVERFLOW =
		"Mailbox index overflow";
	// const std::string debug::PASSWORD_REQUIRED_FOR_NON_SYSTEM = 
	// "Password required for a non-system class";
	const std::string debug::REPEATED_COMMAND_OR_PARAMETER =
		"This command/parameter is already in the map";
	const std::string debug::SYSTEM_USER_NOT_DEFINED =
		": cannot be found in the system";

	/*	*	*	*	*	*	MAIL	*	*	*	*	*	*/

	const std::vector<std::string> mail::CLOSING = {
		"Best", "Sincerely", "Best Regards", "Thank you", "Respectfully", "Sincerely Yours", "Yours Sincerely"
	};

	const std::vector<std::string> mail::ATTACHMENT_NAME = {
		// #0, intentionally left blank
		""
		,
		// #1
		"New Password Instruction For Foxtrot.txt"
		,
		// #2
		"Revised.html"
		,
		// #3
		"InterceptionMsg_28d920d.txt"
	};
	const std::vector<std::string> mail::ATTACHMENT_PLUGIN_NAME = {
		// #0, COMM access plugin
		"705F5"
		,
		// #1, COMM access plugin w/ elevated permission
		"705F6"
		,
		// #2, MACO access plugin
		"964B8"
		,
		// #3, MACO access plugin w/ elevated permission
		"964B9"
		,
		// #4, MACO chatroom access plugin
		"964C9"
		,
		// #5, MACO Surveillant system access plugin
		"2D0BE"
		,
		// #6, MIA access plugin
		"4D28E"
		,
		// #7, [FAKE] COMM access plugin w/ elevated permission
		"14FC6"
		,
		// #8, MACO access plugin v2
		"84A78"
		,
		"10827"
		,
		"305F2"
		,
		"EEA35"
		,
		"C9680"
		,
		"13827"
		,
		"A8780"
		,
		"CEBFD"
		,
		"D5032"
		,
		"B8C6F"
	};

	const std::vector<std::string> mail::ATTACHMENT = {
		// #0, intentionally left blank
		""
		,
		// #1
		"Foxtrot: Add the tenth and twentieth number in the Fibonacci array started with two 1's. Multiply the sum and the difference between the fifth Mersenne prime and the smallest square larger than 1,000. Then convert the decimal value into hexadecimal format with each letter upper case. "
		,
		// #2
		"<!DOCTYPE html>\n<html>\n<body>\n\n<!-- Debug Information -->\n<!-- Created on Jan. 14th, 2012 -->\n<!-- Author: Jason -->\n<!-- My baby's ten days old today! Feel so Good!!! -->\n\n<div style=\"opacity:0.5;position:absolute;left:50px;width:300px;height:150px;background-color:#40B3DF;text-align:center;\"></div>\n\n<div style=\"font-family:verdana;padding:200px;border-radius:20px;border:10px solid #EE872A;text-align:center;\">\n\n<div style=\"opacity:0.3;position:absolute;left:120px;width:600px;height:200px;background-color:#8AC007;text-align:center;\"></div>\n\n<h3>MACO COMMUNICATION SYSTEM DEBUG ENTRANCE</h3>\n<div style=\"letter-spacing:8px;text-align:center;\">Powered By Anoxic</div>\n<div style=\"color:#43B3DF;\">Menu Sample </div>\n<div><span style=\"background-color:#B4229E;color:#dddddd;\">Link Sample</span></div>\n<div style=\"color:#000200;\">and more...</div>\n\n</div>\n\n</body>\n</html>\n"
		,
		// #3
		"$h02a431oj74cjyh4b40i4j74fh8ied4hi;i4hl4hi0h40bbkf30\n"
		"!5y8htwe3f3o903e178dio6;23yqf3jqh6h323j0o9633w5y8w23\n"
		"*mmb;pmebeesfttftupuibujoufsgbdfbsfopipohdsbwbjmbcmf\n"
		"htsecnatsmucrichsrahrednunevetahttnenamrepossi4831e^\n"
		"%53e;d9j0qh6ed8w28oo8ht59d99034q53285y7w;j6g96w59oej\n"
		"(;w285dy5y3o3f345y43358j3wq233i59w332yq58wt98ht59yq0\n"
		"@fl;gpsnvmbpgjejonbujdgpsdpotfdvujwfbhfoutbsfejtdpwf\n"
		"cyllufsseccussitnuocca13212dekafruo;demrifnocdnader#\n"
		"gnidaerretfaliamsihteteled;noitelpedraensi039ld;nep)\n"
		"&4o20dij8bbij0oj74i0c4;j74h48iiec4j78d6mhed6m8j76eh8\n"
	};

	const std::vector<std::string> mail::CONTENTS = {
		// #0
		"\tI know you are wondering who I am and where I come from because you are such a lonely guy that even spams seem to ignore you, but I know you well. You see, I know you just sent a letter to your boss explaining the situation you are in and want to get another job. But you know what, you are going to be promoted and sent to be a spy in another company MATIC. If you are interested in this new work, I suggest you retrieve the letter just sent to make sure you will not be regretful. I know it is hard for you to believe me, but you have to. \n"
		"\tIf you have forgotten your password again, please be reminded that it is what it is. \n"
		"\tBesides, if you cannot access the COMM system, try install the access plugin again. "
		,
		// #1
		"\tI would like to inform you that I am resigning from my position as Programmer for the TAK Agency, effective today.\n"
		"\tThank you for the opportunities for professional and personal development that you have provided me during the last five years. I have enjoyed working for the agency and appreciate the support provided me during my tenure with the company.\n"
		"\tIf I can be of any help during this transition, please let me know."
		,
		// #2
		"\tI am glad to see your excellent work these days. We appreciate your talent and thus decide to send you to infiltrate the MATIC to acquire some confidential information from this company. And its reward will be far tastier than the one of your current job. If you are interested in this, reply to me ASAP, and I will send you relevant information to you if you accept it. "
		,
		// #3
		"\tI am really appreciating the opportunity the company offers me. Of course I will accept this new task, and I am ready to set off. "
		,
		// #4
		"\tI know you are still wondering who I am. But this is a secret. I will come to you when you are in trouble and I know everything you want, but you cannot inquire me everything because you may not even be able to reply to me :)"
		,
		// #5
		"\tI am so excited that you accept it! Here is the information. \n"
		"\tUnder the alias Foxtrot, you can now log in the MACO(MATIC Communication) System with the initial password. Unfortunately we do not know the exact password, but you can simply guess it. It is said that it is almost the easiest password to crack in the world.\n"
		"\tWe are now connecting your adapter to the MACO. Please find the plugin below and refresh your adapter later. After you are in the MACO, you should see an e-mail from Echo, another man we sent in a few months ago. And remember to keep in touch with us to see updated objectives."
		,
		// #6
		"\tWelcome to join MATIC family. We hope you will enjoy your life here. "
		,
		// #7
		"\tGood job! Now you should hack into Split's account to see if you can acquire any information about Echo. We have lost contact with him for a long time. "
		,
		// #8
		"\tThis is exactly what I was expecting you to do for a long time. For some reason I was under strict surveillance from Split so I could not contact you directly before. Now since his account is temporarily locked I could send the letter to you to ask you to sabotage the surveillance system. To do so, you have to hack into another manager - Jason's account to change the permission of Split and then download the surveillance module and install it on your adapter. I tried to do so the last time but was busted. Be careful this time and good luck!"
		,
		// #9
		"\tI do not know which stupid guy maliciously attempt to guess my account's password by blindly typing it wrong ten times so my account was locked and just now did I recover it and canceled such USELESS protection. It is just a waste of time to recover it while I should spend that time doing something more meaningful: I hope that it is not too late because there is going to be a group chat in several minutes. Download the chatroom plugin and enter in the chat-room and listen to what others say."
		,
		// #10
		"\tI know you are excited about what's going on but you have to think about before you tell the intelligence to your boss. Think about it. You do not know exactly how many guys are attending that group chat, and if there are only several guys in the chat and you tell the info to your boss MATIC will somehow know it and suspect everyone who attended the chat. You should know that your company goes out of its way to send you to the Department of Technique in TAK to spy on MATIC, which means it is really hard to be employed.\n"
		"\tOf course, you do not need to worry if your company will blame you while Echo hands in the info and you not: as you can see, no common employee can view the list of attenders. Take it easy. "
		,
		// #11
		"\tHow's it going? Hope you enjoy your life there. We are still unable to contact Echo but we recently received his signal, which meant he was OK. BTW do not forget to send us first-hand information about MATIC. \n"
		"\tIf you ever get any question or try to contact me, reply THIS MAIL.\n"
		"\tBesides, if you have to hack into other employee or employer in the MATIC, you will need this plugin."
		,
		// #12
		"\tI just heard from Echo that he was under strict surveillance so that he was not able to contact anyone other than the staff in the MATIC. However, he is still OK and I am going to hack into the surveillance system to help him out. Besides, I still did not acquire any useful information. I guess it may be that I am still new there but I will try to obtain some. I will send any to you as soon as I got it. "
		,
		// #13
		"\tWelcome to MATIC! As a new employee, you should be aware of your password security. \n"
		"\tAlthough you are in one of the company whose password encryption systems are those of the best in the world, and inside the company you do not have to worry too much about your password being leaked to your workmates, we still recommend you to set your password other than your initial one.As a result, the next time you log in the account, you can use your new password assigned by one of our officer. Once you log in the MATIC system with your new password, your old password will no longer be available. Your password hint is sent to you under the same directory of your adapter. Please check it out and get the password as soon as possible."
		,
		// #14
		"\tThe speed you logged in the account with your new password is amazing! You are one of the few guys who respond to our requests so quickly. Unfortunately, many of our staffs still use pure digits like birthdays or other anniversaries as passwords, which is pretty insecure and are easy to crack, even some of those administrators. It is such a good dream that they will be like you. Thank you for your cooperation!"
		,
		// #15
		"\tI know you are now busy hacking Split's account, and I know one way to get it 每 interrogate. However, such interrogation risks losing your job and is painstaking. We should be kind to British, anyway, so I have done it for you. Surprisingly, I found his birthday is the same as the day we sent first monkey to the space. \n"
		"\tBesides, I think it might be useful if you are going to help someone: please find the attachment below."
		,
		// #16
		"\tHow's it going? I know you are busy dealing with those new to the company. But don't be too worried about them. Remember the day we were just in the company? Well I believe they will learn what to do as time goes. You don't necessarily tell them everything they need to do. It is useless and it is a waste of time (when even you yourself cannot finish your own work in time!).\n"
		"\tI have attached the HTML file you asked me before to revise. I changed the font and the size of the caption so that it looks better than before.\n"
		"\tBTW, are you free this weekend? Would you like to come to my baby's \"100-day Ceremony?\" It is on the evening of this Saturday in my house. RSVP."
		,
		// #17
		"\tGood job! At first I am afraid without my ID number you dare not disable the entire system, but you did! After all, disabling the entire system is dangerous, so I contact you as soon as I can. \n"
		"\tUnfortunately enough, I do not know my complete ID number either because it is encrypted in the surveillance system. All I do know is that my ID number starts with 53 and ends with 890. You can take this for reference. My suggestion is, enable the system immediately and view its log file 每 it may contain some information you want."
		,
		// #18
		"\tI'm glad that you finally made it! However, since I escaped from this system, I bet you I will be spotted soon, so I suggest you to generate a fake person with a fake ID and enable the surveillance system for him. \n"
		"\tYou probably tried to guess my ID or tried to disable surveillance system for other people but was informed that such ID did not exist. The reason is that the system generates new ID for each person in the surveillance system and replaces the old ID with new one to prevent them from escaping. I'm a lucky dog, I admit. As a result, using a new ID does not matter at all. \n"
		"\tHowever, this ID has to follow the rule the ID changes.When I was able to research how the ID keeps changing, I found its way 每 by simply multiplying the old ID with 23, reversing the digit and taking 30 digits beginning from left, which should start with 074 and end with 150 to 155. You can just calculate what my next ID is and all you need to do last is to log in Jason's account again and enable the surveillance system for this ID. Many thanks! :D "
		,
		// #19
		"\tI hope you feel at home in this company. And through these days of observation, I guess you may be good at cracking passwords or something.\n"
		"\tRecently we have intercepted some information from TAK, which we believe contains useful information or other secrets. However, all of the information is encrypted, so we would like you to join us to discover the information beneath those non-sense messy codes.And if you succeed in finding useful intelligence, you will be rewarded considerably.\n"
		"\tPlease think about it twice before sending me your feedback. You can ask anyone around you for advice and they will ALL tell you it's a nice job. We really hope you can join us!"
		,
		// #20
		"\tThings go better when I am in MATIC, and I believe I am so successful as a spy that my \"boss\" there asked me to be a \"spy\" to infiltrate TAK, to test my loyalty to them, I think? I am wondering if it is inappropriate so I wrote a letter to you. \n"
		"\tBesides, I have just rescued Echo from surveillance system so he should be able to contact you."
		,
		// #21
		"\tNicely done! Although Echo currently is unreachable (at least for me), I believe he will make his way to contact me later. If you by any chance met him, tell me to contact us please.\n"
		"\tIn regard to your \"spying,\" I think it is OK. Just remember to send whatever MATIC found about our company and do not fake any intelligence, because as you know, our anti-spy work is the best in the world. The intelligence you found may be faked or created by our agents just in order to deceive those spies from MATIC.\n"
		"\tSo do not believe anything you read and hear there. I believe so far nothing about our company is true in MATIC. But anyway, I am happy and appreciated that you ask me for suggestions like that."
		,
		// #22
		"\tI think twice about the precious opportunity you gave me before, and I firmly believe that it is a great chance for me to develop and challenge my skill. As a result, if you would like to offer that job to me, I will be really appreciated! And I promise I will try my best to do whatever task you assign me!"
		,
		// #23
		"\tI am so happy that you become a member of our agent group! Welcome to MATIC＊s intelligence agency (MIA)! You will soon face many difficult tasks that are challenging, but I am sure you can handle this. \n"
		"\tAs I mentioned in my previous letter, we have just intercepted several intelligence, so you do not have to interception work; all you need is to decode those pieces of messages.\n"
		"\tI have granted permission to log in MIA and to access those data in your MACO system. You can review and download different categories of latest intelligence there. Each task is attached with its reward and the way to upload your findings.\n"
		"\tFor more information, you can go there and read it by yourself. Good luck! However, if you still have any questions, please let me know. "
		,
		// #24
		"\tI am working on my task to crack account information while I was informed that I try to log in by myself to test its validity. However, I do not know the way to do so. Could you please give me something to help me test whether my finding is true? Thank you. "
		,
		// #25
		"\tThis is a letter automatically generated by system to inform you that the last letter you sent to Fizz is not delivered. The error information is \"Unknown Error: Cannot Connect to Server.\"\n"
		"\tHere we attached the letter bounced from our server.\n"
		"\n"
		"\tDear Jason,\n"
		"\tI am working on my task to crack account information while I was informed that I try to log in by myself to test its validity. However, I do not know the way to do so. Could you please give me something to help me test whether my finding is true? Thank you.\n"
		"\n"
		"\tYours, Foxtrot\n"
		"\n"
		"\tPlease do not reply this letter."
		,
		// #26
		"\tI know you are probably wondering what has just happened. There are some technical issues with Jason's mail account, so his account is temporarily not available. However, I may have what you may need.Jason might be too excited before that he forgot to send everything a member in MIA needs.\n"
		"\tIn the attachment attach all the plugins that a member in MIA should install on their adapter, and you may already have already installed several of them. It should have everything you may want, and if you have any problem later and still are unable to contact Jason, I will be there and help you out first :)"
		,
		// #27
		"\tCongratulations! You are now promoted to the manager of the Department of New Resource. Your ID was promoted to 21231 at the same time. \n"
		"\tHigher position means more challenging tasks, and here is a new task for you.\n"
		"\tYou know recently we have been working on No. 1384 每 a really potential product that may bring our company huge profit in the near future. However, there are still some properties to be found about it. Your task is to take a group of select researchers to track its physical and chemical property under C023 to C481 condition, and sent us its daily report from the beginning of the next week. Good luck!"
		,
		// #28
		"\tURGENT! DO NOT INSTALL ANY PLUGINS THAT MATIC PROVIDES! \n"
		"\tThe hash codes of those plugins do NOT match those of plugins in TAK, which means those plugins may by great chance be MODIFIED! If you install them, your adapter may be affected by possible viruses!\n"
		"\tREMEMBER! D.O N.O.T I.N.S.T.A.L.L!"
		,
		// #29
		"\tI am so sorry that I did not send you the letter in time. \n"
		"\tRight now please be informed that you ARE under surveillance system recognized as Echo. You are probably wondering why, and I am here to help you to analyze what happened; it is the only thing I can do now to apology.\n"
		"\tTo remind and figure out what had happened to you, I suggest you log in your account to read old mails and their corresponding recipients, and find why you are called Echo and why you are under surveillance system operated by yourself. Your mail history should still be available.\n"
		"\tI am really sorry."
		,
		// #30
		"\tNow you should be aware of everything. If you look at the names of recipients of the letters that Jason invited you, you will find something interesting. Alpha, Bravo, Charlie, Delta, Echo and Foxtrot 每 your name, all stand for their capitals in military communication system; they are connected. Then you should be reminded about the rule Echo told you about the change in ID. Think about it: what is their relationship? \n"
		"\tIn fact, Echo IS Alpha. As he imprisoned you into surveillance system, he did the same to Bravo to Echo (and then you). This is also the reason why TAK lost contact with them and the reason why TAK keeps sending spies to MATIC 每 because those previously sent are no longer available. Alpha tried to cut down the connection between you and your company to steal your fruit so that he could be promoted. \n"
		"\tBesides, you do not have to be so sad about being watched. What you do there is almost the same with what you can outside. The only difference is that ALL you can do now is to complete those tasks ASSIGNED to you (rather than selecting by yourself) with limited chance and people to communicate privately. Those tasks can sometimes be boring, but some of the others can be helpful for your escape, because those tasks are almost all about decrypting latest intelligence containing some details that may be useful for people who are \"accidentally\" imprisoned like you.\n"
		"\tAs a result, do not lose your grip there. You still have a bunch of opportunities to get the hell out of here!"
		,
		// #31
		"\tI hope you enjoy your life here. You have been doing well for the past few tasks, and here I bring you some new intelligence we have just intercepted. However, this time the way TAK encrypted messages is totally different from the way they did before, so I also forward how to decrypt the information discovered by our agents at the end of this mail. \n"
		"\tFor intelligence, please see the attachment below. I hope you can finish this by this week. \n"
		"\n"
		"\t<Fw: New Way to Decrypt>\n"
		"\tThis time TAK separates messages in pieces and encrypts them in different ways. Our staffs should try to decrypt the messages in an entire group to discover the information beneath it. After decryption, they should sort different pieces of messages correctly.\n"
		"\tNotice: semicolon is the separator. Leave out any characters other than numbers and letters.\n"
		"\tGeneral Rule: The Final Step For Decryption Each Time Is ALWAYS To Add Space(s) Between Characters.\n"
		"\t1. Simply reverse the string\n"
		"\t2. Replace numbers (can be either hexadecimal or decimal) with letters(e.g. 0 to a, 1 to b, 9 to l, a to m etc.)\n"
		"\t3. Move letters forward or backward(e.g.A to C, B to D, C to E, etc.or Z to E, A to F, B to G, etc.)\n"
		"\t4. Move letters \"up\" or \"down\" on the keyboard (look at your Querty keyboard and find this: e.g. A to Q, S to W, E to 3, etc.)\n"
		,
		// #32
		"\tYou have completed your objectives successfully! You have helped all our spies in surveillance system out of here! Now I wish you can log in the accounts of those officers in MATIC to see their reaction (that must be funny) and find more information for us! You are such a talented hacker and I am going to recommend you to our best agent department!"
		,
		// #33
		"\tI am sorry that I am just too excited to send you what you need. When you are busy working for MIA there, we find MATIC has improved their security check, so you will need the plugins I attached below to hack into those officers＊ accounts again. And don't be so nervous about plugins. We have make double check that this plugin is completely safe to use."
		,
		// #34
		"\tI am sorry that I cannot reply your last time as fast as before. As you know, the duty of the director of this freaking intelligence department is to supervise those lazy spies to keep decoding messages. Recently it gets tougher to decode those messages and I am under great pressure, too. \n"
		"\tWorse, even though I had tried my best, the overloaded work forces me to keep working from morning to evening almost without taking a break. I even had to consider changing the appointment that I scheduled with Mrs. Joy who is such a kind and patient teacher that I first knew as a primary school student. Originally I decided to take my daughter there this weekend to ask whether Joy can help Selina with her poor math. I believe Selina will love her and her style of teaching.\n"
		"\tAs a result, I am really sorry that I cannot play badminton with you this weekend. You see, I am really busy.I cannot be busier. I really hope I can even work while I am sleeping.\n"
		,
		// #35
		"\tI believe it is the time that we re-think our strategies. \n"
		"\tAll the bros we painstakingly trained are being stolen and lost since three years ago when we sent them to MATIC. And ironically, the time we retrieve them is when they are sent back again. Before we can come up with the way to counteract that effect, I believe it is relatively easier to update surveillance system. Otherwise everything I did is in vain; we can never keep them."
	};

	const std::vector<std::string> mail::SPAM = {
		// #0
		"\tGreetings, mighty mister! Whats up?\n"
		"\tIt feels like I need a company of a real man! I am sure you are as hot as you page! Online dating sounds thrilling! Lets try it! I have just uploaded two dozens of nude photos to my page. Please, search for me at the dating resource. Join me in a private chat, baby!\n"
		"\tI am looking forward to hearing from you!\n"
		"\tI wait for you! http://mcaf.ee/efk37"
		,
		// #1
		"\tService Desk: We are currently working on a new Microsoft Outlook Webaccess 365 to improve webmail browser for 2014. This is a Redesigned version of hotmail, easy to access mail and folder. Your current webmail will be deactivated soon. To complete this process, reply this mail to fetch your information. Inability to complete this process will render your account inactive. "
		,
		// #2
		"\tObtain a prosperous future and secure the\n"
		"\tadmiration of all for as little as $125.\n"
		"\n"
		"\tDiplomas from prestigious non-accredited\n"
		"\tuniversities based on your life experience.\n"
		"\n"
		"\tNo tests, no classes, no interviews.\n"
		"\tAll diplomas available including bachelors,\n"
		"\tmasters, and doctorates(PhD's).\n"
		"\n"
		"\tNo one is turned down.\n"
		"\n"
		"\tYour diploma puts a University Job\n"
		"\tPlacement Counselor at your disposal.\n"
		"\n"
		"\tConfidentiality assured.\n"
		"\n"
		"\tCALL NOW to receive your diploma\n"
		"\twithin days!!!\n"
		"\n"
		"\t1-603-623-0033, Extension 307\n"
		"\n"
		"\tOpen Every Day Including Sundays\n"
		"\tand Holidays\n"
		,
		// #3
		"\tVery Important Information Regarding Your Outstanding Funds.\n"
		"\tI write to enquire from you if you have received your outstanding funds till now which the answer is NO. You have been under the cage of greedy and non authentic officials who has been deceiving you for a long time in the guise of releasing your funds which they do not have any authority to effect but rather than open up and let you know that they lack the capacity to release your funds, They decided to deceive you till now.\n"
		"\tI have communicated you long time ago and informed you that I am the only person in charge of your funds and I am the only person that can release your funds but it seems that you do not want to believe me due to the fact that you are under the cage and control of those unscrupulous elements / unauthorized persons who has been deceiving you and requesting for one payment or the other from you till now when you are not required to pay any money to get your funds released to you.\n"
		"\tIn fact if you want to receive your outstanding funds immediately, kindly back to me via return mail to enable me give you details.You must keep this mail confidential until your fund is release to you.\n"
		"\tI will give you further details as soon as I hear from you.\n"
		"\tYour urgent attention is highly imperative.\n"
		,
		// #4
		"\tYour email is among the 37 list to be compensated by World Bank/IMF contact!\n"
		"\tClaims Dept Manager Mr.Ego Martins on (info@notspammer.net) for your $1,500.000 ATM CARD. Send him your details such as NAME / COUNTRY / ADDRESS / TELEPHONE to get it!"
		,
		// #5
		"\tI'm Barbara Cole. I'm 15 years old. I live in Bolton UK before my Dad passed away in a car accident 3 years ago. I now live with my step mother in Warrington. My mother died immediately she gave birth to me. My late Dad Mr. Norman Cole was a big business man in UK before he died in a car accident 2008. I am the only child of my Dad, and he died 3 days after the accident. He willed ALL his life savings to me, and I have been trying to collect the funds from the bank but the bank MD CEO refused - he said I should present someone old enough so he can transfer the funds to the person that I can't be in control of the huge amount of funds because I am still a teenager and it is against the UK law. I would have told my step mother to assist me in collecting the funds from the bank but she is not a good woman because my Dad warned me about her before he died. Now that I live with her I now understand that what my Dad said about her was true, because she simply doesn't give me attention she don't care if I am alright or not, all she do is to find what my Dad has left. But of course she will never find it.\n"
		"\tIf you are interested in helping me. Please reply me on my email: bcole013@example.co.jp"
	};

	const std::vector<std::string> mail::SPAM_ADDRESS = {
		// #0
		"hahahana@spam.org",
		// #1
		"fakeservicedesk@true.me",
		// #2
		"diplomacenter@9527.com",
		// #3
		"sssifyra@nospam.net",
		// #4
		"louis_c_bar@pp.qq",
		// #5
		"bbq@bbq.qqb"
	};

	const std::vector<std::string> mail::SPAM_SENDER = {
		// #0
		"Hannah",
		// #1
		"Service Desk",
		// #2
		"Diploma Center",
		// #3
		"Mrs. Sandra Sify",
		// #4
		"Barr. Louis Connor",
		// #5
		"Barbara Cole"
	};


	/*	*	*	*	*	*	STORY	*	*	*	*	*	*/
	const std::string story::WELCOME =
		"\tYou are a common programmer called Mino in an intelligence agency TAK that takes stealthy research for governments. Your job is to hack into numerous accounts to acquire information from many VIPs of every field. However, this job is not as exciting as many people may think, and you want to make some changes and decide to quit this job and start a new one. \n"
		"\tYou log in the company's COMM(communication) system and send an e-mail to your boss saying you want to quit the job in the COMM mail system.\n"
		;

	const std::string story::ID_ECHO = "537029334971829573378924715890";
	const std::string story::ID_FOXTROT = "074564862517781080253407476153";
	const std::string story::LOG_NEW =
		"[Time]\t[Op.]\t[ID]\n"
		"000.902\tEnabled\t*276752487484213957459883000*\n"
		"001.007\tEnabled\t*313014111451997885950027234*\n"
		"001.048\tEnabled\t*898029550489128688913120870*\n"
		"001.407\tEnabled\t*311431566523523711784565814*\n"
		"001.506\tEnabled\t*201548774164504140381098433*\n"
		"001.538\tEnabled\t*112670341394162029207429964*\n"
		"001.756\tEnabled\t*907111835427830253720842152*\n"
		"001.844\tEnabled\t*037709828125220884566346270*\n"
		"002.102\tEnabled\t*420504882097738202333644105*\n"
		"002.483\tEnabled\t*331310118527519657197330930*\n"
		"002.608\tEnabled\t*940972306440310725592718114*\n"
		"003.103\tEnabled\t*591998448403190563683778461*\n"
		"003.543\tEnabled\t*168691102056969386578585384*\n"
		"004.032\tEnabled\t*481091632231807566524325279*\n"
		"004.410\tEnabled\t*840102510872752479818990999*\n"
		"004.806\tEnabled\t*647460870328483955050127108*\n"
		"004.972\tEnabled\t*104322402446412792654597901*\n"
		"005.146\tEnabled\t*023764552951832577098945635*\n"
		"005.157\tEnabled\t*147336569300140945154619225*\n"
		"005.453\tEnabled\t*395580237399760458188206400*\n"
		"005.549\tEnabled\t*902841181102531569327619716*\n"
		"005.907\tEnabled\t*782746341946140058417148479*\n"
		"006.325\tEnabled\t*464735842255622519717105237*\n"
		"006.663\tEnabled\t*326144247898020479228004143*\n"
		"007.143\tEnabled\t*554841476235180977334132657*\n"
		"007.471\tEnabled\t*217417585722292180795616292*\n"
		"007.621\tEnabled\t*904166572784963726504343632*\n"
		"007.740\tEnabled\t*534635702632618139614801112*\n"
		"008.153\tEnabled\t*547069282791411730753979516*\n"
		"008.329\tEnabled\t*024396711732389984946517980*\n"
		"008.359\tEnabled\t*673237972204160635066492707*\n"
		"008.523\tEnabled\t*648405166409450213550849306*\n"
		"008.895\tEnabled\t*370293349718295733789247158*\n"
		"009.357\tEnabled\t*864838249014052164962169966*\n"
		"009.663\tEnabled\t*061410545596272249938877229*\n"
		"009.745\tEnabled\t*816526606348528833133800876*\n"
		"009.862\tEnabled\t*571533926003860639619037865*\n"
		"009.915\tEnabled\t*486373688094435992428409318*\n"
		"010.385\tEnabled\t*414819764442362224232453545*\n"
		"010.569\tEnabled\t*502185686512952253538563393*\n"
		"010.668\tEnabled\t*586695871998776469915167726*\n"
		"011.149\tEnabled\t*855714234079472772483807432*\n"
		"011.280\tEnabled\t*872029454851566898305184981*\n"
		"011.523\tEnabled\t*847862235451035320886405686*\n"
		"011.786\tEnabled\t*858395631910926378965847580*\n"
		"011.863\tEnabled\t*658445351261663118750793012*\n"
		"012.345\tEnabled\t*301555657397374847852888699*\n"
		"012.709\tEnabled\t*836262530436792436833129643*\n"
		"012.899\tEnabled\t*700828776458997224369129208*\n"
		"013.002\tEnabled\t*645511857533200179534020732*\n"
		"!ERROR! TRANSMISSION DESTROYED. CONTACT SUPPORT CENTER"
		;
	const std::string story::LOG_OLD = "No recent activities";

	const std::string story::OUTRO = "Congratulations! If you were really on your own to achieve this, you must see this a milliono times (this sentence is written to talk to myself).\n"
		"It is 1634 PST @ 110514, on my Math 20C class in UCSD. And I just went back to check the time I have an idea to create such a game, it is 020814, almost nine months ago, although I originally think it won't take such a long time to make it.\n"
		"This is a game developed completely by myself, Anoxic, with pure interest to develop a game based on console. However, by the time I am writing all these things by myself in Warren Lecture Hall, I am not sure if this game is bug-free. I just want to write something to commemorate such a moment.\n"
		"Thanks for all the people supporting me to make it, although I know it is only me doing this job :)";


	const std::vector<int> story::CHATROOM_INTERVAL = {2000, 1000, 500, 500, 7000, 3000, 7000, 10000, 2000, 5000, 5000, 2000, 3000, 2000, 3000, 1000, 500, 3000, 1000, 100, 300, 500, 2000};

	const std::vector<std::string> story::CHATROOM = {
		"\t/YOU ENTER THE CHATROOM/",
		"\t/FOXTROT IS ONLINE/",
		"\t/YOU ARE NOT ALLOWED TO TALK/",
		"<Mari>\tGood.",
		"<Jason>\tSo that's all the guys attending my party?",
		"<Split>\tI guess so. Let's start right away coz Foxtrot is online.",
		"<Jason>\tOK. Now let's start this.",
		"\tSo AFAIK this is to inform y'all that TAK is now trading with a new company with great bulk.",
		"\tFrom our intelligence, the ID No. of what inside the box is something that we have never met before.",
		"<Split>\tWhat does it mean?",
		"<Jason>\tIt might probably indicate that we are going to lose another profitable meat.",
		"\tHowever, we have sent another of our friends to see what the hell that is.",
		"<Split>\tSo the rest of you have to work hard on another task.",
		"\tI will send you the details via email.",
		"<Jason>\tAnd that's all for this short meeting.",
		"\tThank you for attending and good luck.",
		"<Mari>\tOK, bye.",
		"<Goril>\tCopy.",
		"<Split>\tOK then. I will talk to you personally about this.",
		"\t/MARI IS OFFLINE/",
		"\t/SPLIT IS OFFLINE/",
		"\t/GORIL IS OFFLINE/",
		"\t/YOU ARE EVICTED FROM THE CHATROOM/",
	};

	const std::vector<std::string> story::CLYDE_ANSWER = {"Joy", "Selina"};

	const std::vector<std::string> story::CLYDE_QUESTION = {"What is the name of your first teacher you ever met?", "What is the name of your son/daughter?"};

	const std::vector<std::string> story::INTRO = {
		// #1
		"This is a game based on console. If you are familiar with \"cmd.exe\" in Windows OS, then the operation of this game shouldn't be a great deal. In this game we call this user interface \"adapter.\" To interact with adapter, you are required to input command each time you ask it to do something. For example, type \"next\" and press ENTER on your keyboard to see further instructions. "
		,
		// #2
		"Great! It seems that you have become familiar with this game. Besides inputting a single word, sometimes the game would like you to input a command with one parameter. When this happens, you can type the command following a space and following the parameter. For example, type \"next paragraph\" and press ENTER to see further instructions. "
		,
		// #3
		"Excellent! Now you have acquired the basic operation of this game. This game includes a story waiting you to discover, and it also requires your knowledge to decipher each valuable information after every piece of message you have seen. Good luck!"
		,
		// #4
		"Good! You have successfully guess what to enter to let the adapter show what you want to see. However, sometimes you have no clue to know what to input. When this happens, type \"?\" (A question mark) to see all available commands. "
		,
		// #5
		"Nice! Now enter anything to start the game."
	};

	const std::vector<std::string> story::PASSPHRASE = {
		// #0, intentionally left blank
		""
		,
		// #1
		"thingsdevelopedquickly;wehavemanynewemployeesthiswe"
		,
		// #2
		"ek;formulaofidinmaticforconsecutiveagentsarediscove"
		,
		// #3
		"redandconfirmed;ourfaked21231accountissuccessfullyc"
		,
		// #4
		"rackedbythemtoreleasetheprisoners;serversareallupda"
		,
		// #5
		"ted;companydciswillingtocooperatewithus;myboystoldm"
		,
		// #6
		"e1384issopermanentthatevenunderharshcircumstancesth"
		,
		// #7
		"eycanstillstaythesame;thereissomethingwrongwithgori"
		,
		// #8
		"lla;oldaddressestothatinterfacearenolongeravailable"
		,
		// #9
		";switchtheleverthreetimesaweektoseewhatisgoingtohap"
		,
		// #10
		"pen;dl930isneardepletion;deletethismailafterreading"
	};

	const std::vector<std::string> story::STORY = {
		// #0
		"\tHowever, just as soon as you send the quitting letter, you receive an anonymous letter in your public mailbox telling you not to quit the job."
		,
		// #1
		"\tWith doubt you retrieve the letter in company's COMM system.\n"
		"\tThen you receive a letter from the manager. "
		,
		// #2
		"\tAs the previous letter predicts, the manager tells you he is satisfied with your work and decides to ask you to infiltrate the MATIC, which is the TAK's competitor for a long time."
		,
		// #3
		"\tYou reply the letter to accept the offer. "
		,
		// #4
		"\tWith excitement, you now realize that this all could be brought by Pluto, but who is he? You want to ask him, but he seems to know what you want."
		,
		// #5
		"\tYou may try but fail. Then you receive the information about your MATIC account."
		,
		// #6
		"\tYou return to your adapter and refresh the status and log in the MACO system. However, instead of receiving email from Echo, you are warmly welcomed by the \"new\" manager, Split. "
		,
		// #7
		"\tYou return to your adapter and log in the COMM system. And you receive a letter from Fizz. "
		,
		// #8
		"\tBut without any hints and suggestions, you are confused: how is it supposed for you to guess Split's password? You try to guess Split's password anyway, and after ten times of failure, you get a message from your adapter that the account of Split is temporarily locked.\n"
		,
		// #9
		"\tYou log in your MATIC account, and find yourself receive a new letter from Echo."
		,
		// #10
		"\tYou are happy to finally contact with Echo and are excited about new task. However, having no idea where to start and how to crack the password, you are puzzled and do not know what to do. And Split seems to have recovered his account and sends you an email to ask you to attend a group chat. "
		,
		// #11
		"\tYou are glad that Split does not suspect you. And you think it is better to attend the group chat and then think about the way to get the password. After entering the chat room, you realize that it is just a short meeting and you are simply not allowed to chat because of your identity. The chat has already begun for a few minutes and you seem to have missed something important."
		,
		// #12
		"\tYou seem to have acquired some information about TAK that you know nothing about, but you feel a bit excited because you also seem to get some intelligence that MATIC too is spying on your origin company. You are going to tell this to Fizz. However, you receive a letter from Pluto."
		,
		// #13
		"\tWith the last successful prediction, you think it is a good idea to believe Pluto. But you still log in the COMM to see if there is any new objective. And you find another new letter. "
		,
		// #14
		"\tAnd you reply the letter without mentioning anything you learned in the group chat. "
		,
		// #15
		"\tYou are kind of glad that Echo was unable to contact TAK so that you can say whatever you want to say without worrying about it. Now you start to consider the way you can follow Echo's instruction to hack into Jason's account to disable the surveillance over Echo so both of you can keep spying. Having no idea what to do, you log in MATIC system to see if there is anyone you can ask for help. And surprisingly, you receive a letter from Tyler, an officer in the Department of Security. He told you to change your password immediately. "
		,
		// #16
		"\tYou find the received file in your directory. The hint says your password in a nerdy way. "
		,
		// #17
		"\tIt is not a difficult task for such a genius like you, and you got the decimal value is\n"
		"\t\t(55 + 6765) * (8191 - 1024) = 48878940,\n"
		"\tAnd the hexadecimal value is 2E9D55C."
		,
		// #18
		"\tYou log in the MATIC system again, and receive another letter from Tyler."
		,
		// #19
		"\tWhat's in the letter is a bit informative. Is the password of Jason's account his birthday? But you can by no means get his exact birthday because you are not familiar with him at all. Then you think about hacking into Split's account and then finding if there is any letter indicating Jason's birthday. However, you do not know anything about Split, either. As you are trying to guess Split's password, you receive a letter from Pluto."
		,
		// #20
		"\tAlthough Pluto does not explicitly tell you what Split's birthday, you know what it is (June, 11th). And considering the fact that Pluto mentioned that Split is a British, the password should be 1106. It is correct. After checking his email box, you found Split careless and sloppy when you have to wade through piles of spam mail to find what you really need. And after going through all the mails, you found one particularly informative. "
		,
		// #21	
		"\tAlthough Jason seems to have mentioned something important, but you still know nothing personal about Jason. To acquire more information, you downloaded the file in the attachment. You hope to find something in the file or website. But when you open the file, you find it is designed for a company. However, when you look at its source code, you find something really useful. At the head of the source code is the date when the file is created, and Jason commented by the side that \"My baby is ten days old today.\" It is Jan. 4th. \n"
		"\tYou successfully log in to Jason's account using the password 20110104. And you find the surveillance system under Jason's control menu. However, when you try to disable the surveillance system for Echo, you did not know Echo's exact ID number. Finally, you decided to disable the entire surveillance system."
		,
		// #22
		"\tAs soon as you disable the entire surveillance system, you received the letter from Echo."
		,
		// #23
		"\tSince Echo does not know his ID number either, you think it may be a good choice to follow his advice. You return to Jason's account and re-enable the system again, and you tried to read the log file. You found that the ID number of Echo is 537029334971829573378924715890 (30 digits). You disable the surveillance system for this ID."
		,
		// #24
		"\tYou sign out and log in using your \"real\" name, and receive another letter from Echo."
		,
		// #25
		"\tYou follow what Echo tells you to do: \n"
		"\t537029334971829573378924715890 * 23 = 12351674704352080187715268465470\n"
		"\tAfter reversing, the number is 07456486251778108025340747615321.\n"
		"\tThe first 30 digit is 074564862517781080253407476153."
		,
		// #26
		"\tYou enable the surveillance system for this ID. After all is done, you go back and check your own mailbox, and find a letter new from Jason."
		,
		// #27
		"\tTo infiltrate TAK while you are a spy in MATIC? You think it is a bit amusing to be a double agent. But anyway, you decided to ask your boss in TAK first. You log in COMM system and send an email to Fizz to ask what you should do next. "
		,
		// #28
		"\tLater you receive the reply from Fizz. Fizz says it is OK to be a double spy, and he applauds your work. "
		,
		// #29
		"\tYou sigh. But what Fizz told you reminds you of something talked about when you were still new to the company. In a group chat the first day you entered the company, Jason mentioned a mysterious transaction of great bulk. Is that piece of information faked? You don't know. However, you log in MACO system and tell Jason that you accept the job."
		,
		// #30
		"\tSoon you receive the reply from Jason. It seems that he is happier than you that you join the group. "
		,
		// #31
		"\tYou log in MIA system and found the only available task for you is to crack a pair of account and password. You accept it and download the intelligence pack. "
		,
		// #32
		"\tThen you think, well, I should ask Jason for more information about the plugin to access COMM system and elevated permission plugin instead of Fizz. You return to MACO system and write a letter to Jason."
		,
		// #33
		"\tHowever, this letter is not sent successfully. You receive a letter from system that your letter is returned from server due to unknown error. "
		,
		// #34
		"\tYou are a bit confused. What happened? Why can't you send any email to others? As you are wondering your next action, surprisingly, you received a letter from Echo."
		,
		// #35
		"\tAfter installing all the plugins, you try to log in Bandit's account again. You find Bandit is the manager of TAK's Department of New Resource, and you find the following mail particularly informative. "
		,
		// #36
		"\tThen you decided to tell what you find to Fizz first before you do to Jason. However, you received a letter from Pluto. "
		,
		// #37
		"\tUnfortunately, it is too late for Pluto to send this message to you. You have already installed all the plugins. You find that your COMM access plugin has been uninstalled so that you can only log in MACO system. However, when you log in, you find the information says \"You are under surveillance system.\" All the command you have is to check your current status. "
		,
		// #38
		"\tYou are so confused because you are FOXTROT, not ECHO, but the screen clearly tells you that you are Echo. What's more, what does the OPERATOR means? Does that mean the one who put you under surveillance system? Is there something wrong with the server that caused such amusing problem? You log out and try to re-log in, hoping the server will be OK this time. However, you receive another letter from Pluto."
		,
		// #39
		"\tYou log in MACO system again and read your letters. You find the mail Jason first sent you which invited you to join MIA, and you find the names of its recipients a little informative. They are names like \"Alpha, Bravo, Charlie, Delta ...\" which reminds you of something. Then you find the mail Echo sent you about his \"next ID,\" could that be YOUR ID number? With so many problems, you receive another letter from Pluto."
		,
		// #40
		"\tEven though Pluto tries to comfort you, you are still worried about not being able to contact Fizz. You log in MACO and receive a letter from Jason. In the letter, Jason called you \"Echo,\" and he told you something about the new intelligence needed to decrypt and new ways of encryption."
		,
		// #41
		"\tThen you download the attachment and get a pile of messy codes. After decryption following the rules above, you get ten pieces of fragmented strings. Then you rearrange them, and get a complete letter that contains information far more important than you can ever imagine. "
		,
		// #42
		"\tYou find that account 21231 is faked and something important about 1384. If 21231 is faked, is that possible that agents from TAK will hack into surveillance system to help you out? However, it is just mere assumption. You submit your findings and wait for the reply. However, when you log out, you find your COMM access is recovered; you can access COMM now. Wondering what has happened, you find a new letter from Fizz. "
		,
		// #43
		"\tYou are more confused because what Fizz says in the letter does not make any sense at all 每 you are right there under surveillance and all you have done is that you submitted your findings about intelligence. You have done nothing about helping others. Who did? Could that be Alpha? But why bothers sending you to surveillance system and using YOUR account to complete such a difficult task with calculated traps rather than doing so on his own? The more you think, the more you feel puzzled. Despite all the confusion, you try to log in MACO system. However, you receive the same warning that you are not allowed to log in because you do not have permission to do so. You log in COMM system again and find another letter from Fizz attached with what you want. "
		,
		// #44
		"\tAfter installing the plugins, you try to log in Jason's and Split's account again. However, you find Split has changed his password while Jason still uses his old password (what a careless man). You read his letter carefully and find the mail from someone called Clyde catch your attention. This is a letter talking about private matters."
		,
		// #45
		"\tIt seems that this letter contains important personal information, so you think about resetting the password of Clyde's account. Then you find the questions are about the name of first teacher he ever met and the name of his son/daughter 每 apparently from the letter you know that the answers are Joy and Selina. And when you log in his account, you read a letter that contains information that you have no idea that you can ever imagine. "
		,
		// #46
		"\tWhat the hell is that \"when they are sent back?\"\n"
		"\tAm I part of \"they\" ?"
		"\tWho am I ?"
		// It is so amazing that I coincidentally write exactly 40 pieces of stories. 
	};

}


void prompt_abortion(const std::string& str) {
	if (str == "")
		// Do not display empty message
		return;
	std::cout << "[ABORT]\t" << str << std::endl;
}

void prompt_debug(const std::string& str) {
	if (str == "")
		// Do not display empty message
		return;
	std::cout << "[-----INTERNAL ERROR-----]: " << str
		<< std::endl;
}

void prompt_help(const std::string& str) {
	if (str != "") {
		command_catalog cc;
		std::string pmt = str + "\t";
		// If the input string is too short, adjust the tab length
		if (str.length() < 8)
			pmt += "\t";
		pmt += cc[str];
		prompt_plain(pmt);
	}
}

void prompt_info(const std::string& str) {
	if (str == "")
		// Do not display empty message
		return;
	std::cout << "[INFO]\t" << str << std::endl;
}

void prompt_plain(const std::string& str) {
	if (str == "")
		// Do not display empty message
		return;
	std::cout << str << std::endl;
}

void prompt_warning(const std::string& str) {
	if (str == "")
		// Do not display empty message
		return;
	std::cout << "[WARN]\t" << str << std::endl;
}

void prompt_dir(const std::string& dir) {
	std::cout << "[DIR]\t" << dir << std::endl;
}

void prompt_separator() {
	std::cout << "==============================================" << std::endl;
}

std::string prompt_input(const std::string& str) {
	std::string ret;
	do {
		// Transform str so that it can be displayed before [USER] ...
		if (str != "")
			std::cout << "\t>>\t" << str << std::endl;
		std::cout << "[USER]\t>>\t" << std::flush;
		std::getline(std::cin, ret);
		// Does not allow empty string
	} while (ret == "");
	// Remove the first few space(s)
	if (ret.find_first_not_of(' ') != std::string::npos)
		return ret.substr(ret.find_first_not_of(' '));
	else 
		return "";
	return ret;
}

std::pair<std::string, std::string> prompt_login() {
	std::string str1, str2;
	std::cout << "Username: " << std::flush;
	std::getline(std::cin, str1);
	std::cout << "Password: " << std::flush;
	std::getline(std::cin, str2);
	// Does not allow empty string
	while (str1 == "" || str2 == "") {
		prompt_warning(dialog::warning::INVALID_EMPTY_STRING);
		std::cout << "Username: " << std::flush;
		std::getline(std::cin, str1);
		std::cout << "Password: " << std::flush;
		std::getline(std::cin, str2);
	}
	return make_pair(str1, str2);
}
