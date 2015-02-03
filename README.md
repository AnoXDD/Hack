# Hack
Ver 1.0.0 (unfinished)

**[Introduction]**
This is a game based on windows console. The main objective of the game is to follow the information given by the game as the game is developed and triggered by what the user does. There is no branch of the game. 
In the game the player plays a character of a programmer at the beginning of the game, and just before the player is going to quit the job, he received a letter from someone mysterious. Following what the mysterious man says, he starts to discover something strange and exciting about the company that he is employed and that is his company's competitor. 
To control the character, the player needs to repeatedly type and order the game what to do next, just as what we do in command line. 

**[Development Phase]**
Currently this game has finished the first episode. However, I am not sure if I will complete its sequel.
In the first episode, the story is designed to leave something unsolved in the end, so it is possible to finish the sequel based on what is left in the end. To avoid spoiler, the entire story line is *Hack/story.txt*. Detailed about this file will be given below.
I would like to add tab autocomplete to make the command run faster. I tried GNUWin32 but it did not work for me (readline5.dll is something wrong, probably incompatibility of c and cpp).

**[Game Structure]**
The game defines three main classes. menu (in menu.h), dialog (in dialog.h) and command_catalog (in command_catalog.h), and one drive class, game_core (in game_core.h), which pushes the game forward.
The usage of these classes are easy to understand given their names. 
Here are only listed a rough introductions of each class. For more information, see the comment blocks in each header file.

	**[menu.h]**
	Menu is the basic element of the game, which involves the operation that the user mostly access. The menu handles almost everything about the jump between menus. However, the more advanced operation is to be included in game.
	Basically, menu only have control over what the menu is supposed to do, and can only control what within the menu. 
	This class have numerous derivative classes implemented for different purposes, including system, which includes accounts, which include mailboxes, which have two other derivative types, inbox and outbox, which should include mails, and tracker, which keep a record of the game progress, plugin, keep a record of plugins that required for access for certain menus, and utility menus, including chatroom, task_menu, surveilent, which are used during several levels of the game, and can be either accessible or inaccessible as the game progresses. 
	By "include(s)" mentioned above, the program presupposes such relation by converting the classes during **run-time**. In the entire project, in order for the program easier to code and debug, the public functions of parameter uses menu.h as opposed to its correpsonding derivative types even though it is supposed to be so. However, within the functions the program will explicit case the classes and do the job properly. 

		**[sys.h]**
		(As of the description included in the header file)
			*This is a communication system used to establish connection between "account."*
			*In this class, cmd stands for the username and the pointer to its corresponding account class. para stands for the pair of username and password.*
			*This class controls the permission that the player can access by adding or removing the account from "para" list. For more information, see the definition of enter(string, string).*
		The program presupposed that each sub-menu of sys.h is account.
		There are two systems in this game, COMM and MACO.
		The account's information is stored in system's para. 

		**[account.h]**
		This class is a class that handles different accounts. 
		For information about what will happen when the user attempts but failed to give correct account/password, see the comment block in the file for more information.

		**[mailbox.h]**
		This is an abstract class, which derives two other boxes, inbox and outbox. 

		**[inbox.h, outbox.h]**
		Handles the mail and send/receive function. 
		However, sending mails across two different system is not supported so far. By sending a message to another account under the same system, the recipient will automatically call receive() function.

		**[mail.h]**
		The most basic and one of the most important submenus in the game. 
		It is an email transmitting two accounts. When the sender generates one in his mailbox, a copy of another email will be generated (but not the same thing) in the recipient's mailbox. 
		The reply and the detail function is used for some trigger.