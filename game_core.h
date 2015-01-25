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
	void init();
	/* Introduce the basic instructions to the player */
	void intro();
	/* End of the game */
	void outro();

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
	// inbox of the main menu
	menu* main_inbox;
	// outbox of the main menu
	menu* main_outbox;
	// Story line of the game
	menu* story_line;

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

