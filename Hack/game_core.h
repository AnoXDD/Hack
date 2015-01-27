/*
	game_core.h

	This class is the core component of the game.

	Created on 052314
	Author: Anoxic
	*/

#pragma once

#include <utility>

#include "dialog.h"
#include "menu.h"

class game_core {
	/* If the player reaches this level, the player wins, and the game quits */
	const static int MAX_LEVEL;
	/* The time of freeze after each deplay (to make it real for internet connection) */
	const static int SLEEP_DELAY;
	/* The number to indicate that user has successfully save the game progress and want to quit */
	const static int QUIT;
	/* Current level */
	int level;
	/* Pointer to current menu displayed */
	menu* current;
	/* Act or develop the stories */
	void act();
	/* Develop story at this level */
	void develop_at(int lev);
	/* Update story, will call develop_at(int) */
	void inc_level();
	/* Initialize the game, including loading the archive file */
	bool game_init();
	/* This is included in the construction function. Return if an archive file is loaded */
	void init();
	/* Introduce the basic instructions to the player */
	void intro();
	/* End of the game */
	void outro();

	/* ***************** Game saving machanism ***************** */
	/* A pointer to store the list of each mail */
	std::vector<menu*>* maillist;
	/* Save the game. Return if saving is successful */
	bool save();
	/* Load the game. Return if loading is successful */
	bool load();
	/* Quit the game. 
	 Return game_core:QUIT to indicate saving successful, current level to indicate failure
	 */
	int quit();
	/* Decrypt the string */
	const std::string decrypt(const std::string&);
	/*
	 Encrypt the string 
	 The encryption uses XOR. The key is to be generated randomly, and located at the first character of the encrypted string returned.
	 */
	const std::string encrypt(const std::string&, char);
	/* 
	 Wrap up all the progress that can be saved
	 Include: 
	   1) level,
	   2) how many lines have been printed so far, 
	   3) status of plugins, 
	   4) read, time and attachment status of every mail
	 */
	const std::string archive();

	/* 
	 Utility function. Split one string into two by its first space (" ") 
	 @Return: A pair of split strings if space exists.
	          Else a pair of string, in which the first element is the original string, and the second element is an empty string
	 */
	std::pair<std::string, std::string> split(const std::string&);
	/*
	 Utility function. Blur the information of letter from Pluto
	 */
	void pluto_blur(menu*);
public:
	/*	*	*	*	*	Here are all the menus in the game	*	*	*	*	*	*/

	/* MAIN MENU */
	menu* main_menu;
	menu* extension;
	/* inbox of the main menu */
	menu* main_inbox;
	/* outbox of the main menu */
	menu* main_outbox;
	/* Story line of the game */
	menu* story_line;
	/* Save and exit */
	menu* exit;
	/* This a dummy menu that only stops returning when user enters "exit" */
	menu* exit_dummy;

	/* SYSTEM */
	menu* comm;
	menu* maco;

	/* Here are all the accounts to be used in the game, sorted alphabetically */
	menu* Alpha;
	menu* Bandit;
	menu* Clyde;
	menu* Echo;
	menu* Fizz;
	menu* Foxtrot;
	menu* Jason;
	menu* Mino;
	menu* Pluto;
	menu* Split;
	menu* Tyler;

	/* Utility */
	menu* chat;
	menu* submit;
	menu* surveil;
	menu* mia;

	game_core(): level(0) {
		init();
	}
	~game_core();

	/*
	 Authenticate whether the user has requried plugin to enter this menu
	 If true, enter the menu without prompt; Otherwise return false and prompt [abort]
	 */
	bool authenticate(menu*);

	/* Advance to this level */
	void advance_to(int lev);
	void start_game();
};

