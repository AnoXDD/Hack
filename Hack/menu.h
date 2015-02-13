/*
 * menu.h
 * This is a base class for all menus
 *
 *  Created on: Mar 16, 2014
 *      Author: Ano
 */

#ifndef MENU_H_
#define MENU_H_

#include <map>
#include <string>
#include <vector>
#include <utility>

#include "dialog.h"

/*
  This function should also have an enter() function to execute everything it should do when entered. enter() includes act() and prompt_welcome(), and any other functions to be added in future update
  */

class menu {
	/* If false, cannot return to previous menu */
	bool returnable;
	/*
	 If true, account and password required before entered
	 All objects based on "menu" have this member as false
	 This variable is set to TRUE in "system" only
	 */
	bool auth;

	/*
	 This is a function that helps the class to detect some trigger effect of what the player does (e.g. When entering "refresh", the "mailbox" class would like to call refresh() function, too)
	 This function is called only if it passes the check in enter(), i.e. the params are legal. Then enter() will pass exactly the same params to this function
	 The programmer can customize any effect if the players enter any submenu, but ATTENTION: IT SHOULD ONLY CALL THE FUNCTION INSIDE THE CLASS. Anything that will trigger the development of the story is not considered to be a part of the code here
	 */
	virtual void act(const std::string&, const std::string& = "");
	/*
	 To display a help menu
	 This function is virtual so that class like "mailbox" can overwrite it
	 */
	virtual void display_help();

	/* The four functions below can be overwritten by subclasses to achieve different tasks */
	virtual void prompt_invalid_command(const std::string& name) {
		prompt_abortion(name + " : " + dialog::abortion::INVALID_COMMAND);
	}
	virtual void prompt_invalid_params(const std::string& name, const std::string& para_str) {
		prompt_abortion(para_str + " : " + dialog::abortion::INVALID_PARAMETER + " for " + name);
	}
	virtual void prompt_missing_params(const std::string& name) {
		prompt_abortion(dialog::abortion::MISSING_PARAMETERS + name);
	}
	virtual void prompt_unnecessary_params(const std::string& name) {
		prompt_abortion(dialog::abortion::UNNECESSARY_PARAMETERS + name);
	}

	void init() {}
	/* Refresh the directory of all the object itself and its sub-menus (and sub-sub-menus by recursion) */
	void refresh_child_dir();
protected:
	/* The pointer to parent menu */
	menu* parent;
	/*
	 This description and information to be displayed when the menu is accessed
	 * [DIFFERENCE]	Description is displayed called from dialog::prompt_plain()
	 *				Information is displayed called from dialog::prompt_information()
	 *				Besides, information is displayed before description
	 */
	std::string desc, info;
	/* The caption of the menu */
	std::string caption;
	/* The directory of this menu; DOES include caption; ends with "/" */
	std::string dir;
	/*
	 Access ID to indicate which plugin has to be installed in order to access 
	 The test will be done in "game_core"
	 */
	std::string access_ID;
public:
	typedef std::map<std::string, menu*> menu_map;
	typedef std::map<std::string, std::string> para_map;
	/*
	 This is to be changed for debugging 
	 Please be noted that after change this several errors may still occur
	 Major changes are in game_core.cpp, watch for compiler-undetectable errors!!!
	 */
	typedef std::vector<menu*> maillist_vector;
protected:
	menu_map cmd;
	para_map para;
public:

	/* Constructors */
	/* *************************** [CONSTRUCTOR PARAMS QUICK VIEW] *******************************
	 * All auth is set to false by defalt
	 ([title])
	 (*parent, [title], [auth]) -> CAN BE USED TO GENERATE A DISPLAY-INFO-ONLY MENU
	 (*parent, title, description, [info])
	 (*parent, title, cmd, [auth])
	 (*parent, title, cmd, para, [auth])
	 */
	/* This constructor can be used to generate a main menu that cannot be returned to previous menu */
	menu(const std::string& title = "Untitled"):
		returnable(false), auth(false), access_ID(""), parent(0), desc(""), info(""), caption(title), dir("/"), cmd(menu_map()), para(para_map()) {
		init();
	}
	/* This constructor can be used to generate a display-info-only menu */
	menu(menu* par, const std::string& title, const std::string& d, const std::string& i = ""):
		returnable(true), auth(false), access_ID(""), parent(par), desc(d), info(i), caption(title), dir(par->get_dir() + title + "/"), cmd(menu_map()), para(para_map()) {
		init();
	}
	menu(menu* par, const std::string& title = "Untitled", bool pw = false):
		returnable(true), auth(pw), access_ID(""), parent(par), desc(""), info(""), caption(title), dir(par->get_dir() + title + "/"), cmd(menu_map()), para(para_map()) {
		init();
	}
	menu(menu* par, const std::string& title, menu_map list):
		returnable(true), auth(false), access_ID(""), parent(par), desc(""), info(""), caption(title), dir(
		par->get_dir() + title + "/"), cmd(list), para(para_map()) {
		init();
	}
	menu(menu* par, const std::string& title, menu_map list1, para_map list2):
		returnable(true), auth(false), access_ID(""), parent(par), desc(""), info(""), caption(title), dir(par->get_dir() + title + "/"), cmd(list1), para(list2) {
		init();
	}
	menu(const menu& Menu) {
		this->returnable = Menu.returnable;
		this->auth = Menu.auth;
		this->access_ID = Menu.access_ID;
		this->parent = Menu.parent;
		this->desc = Menu.desc;
		this->info = Menu.info;
		this->caption = Menu.caption;
		this->dir = Menu.dir;
		this->cmd = Menu.cmd;
		this->para = Menu.para;
	}
	menu& operator=(const menu& Menu) {
		this->returnable = Menu.returnable;
		this->auth = Menu.auth;
		this->access_ID = Menu.access_ID;
		this->parent = Menu.parent;
		this->desc = Menu.desc;
		this->info = Menu.info;
		this->caption = Menu.caption;
		this->dir = Menu.dir;
		this->cmd = Menu.cmd;
		this->para = Menu.para;
		return *this;
	}
	virtual ~menu() {}

	/**************************************************************/
	/* Function */
	/* Enter the menu */
	virtual menu* enter(const std::string& name, const std::string& para = "");
	/* Return to the previous menu */
	virtual menu* back();

	const std::string get_access_ID() const {
		return access_ID;
	}
	void set_access_ID(const std::string& str) {
		this->access_ID = str;
	}

	bool add_cmd(menu_map::value_type val) {
		if (val.second->parent != this) {
			// the second element's parent is not this menu
			prompt_abortion(dialog::debug::INVALID_SUBMENU_PARENT);
			return false;
		} else {
			return cmd.insert(val).second;
		}
	}
	bool add_cmd(const std::string& str, menu* m) {
		return add_cmd(make_pair(str, m));
	}
	bool remove_cmd(const std::string& str) {
		return cmd.erase(str) != 0;
	}
	const bool has_cmd(const std::string& str) {
		return (cmd.find(str) != cmd.end());
	}
	const menu_map& get_cmd() const {
		return cmd;
	}
	const menu_map::size_type get_cmd_size() const {
		return cmd.size();
	}
	/*
	 Get the pointer to a menu indexed by a key
	 As an interface for cmd.find()
	 */
	menu_map::iterator find_cmd(const std::string& key) {
		return cmd.find(key);
	}
	
	/* This function can also change the value of this parameter */
	void add_para(const std::string& str1, const std::string& str2) {
		para[str1] = str2;
	}
	bool remove_para(const std::string& str) {
		return para.erase(str) != 0;
	}
	const bool has_para(const std::string& str) const {
		return (para.find(str) != para.end());
	}
	const para_map::size_type get_para_size() const {
		return para.size();
	}
	/* Clear the para list */
	void clear_para() {
		para.clear();
	}

	void set_returnable(bool returnable) {
		this->returnable = returnable;
	}
	const bool is_auth() const {
		return auth;
	}

	/* This method is not set as const because "mail" has to overwrite it */
	const std::string& get_desc() {
		return desc;
	}
	void set_desc(const std::string& desc) {
		this->desc = desc;
	}

	const std::string& get_info() const {
		return info;
	}
	void set_info(const std::string& info) {
		this->info = info;
	}

	const std::string& get_dir() const {
		return dir;
	}
	void set_dir(const std::string& dir) {
		this->dir = dir;
	}

	const std::string& get_caption() const {
		return caption;
	}
	void set_caption(const std::string& caption) {
		this->caption = caption;
		this->refresh_child_dir();
	}

	/*
	 This method should be called every time that the menu is entered
	 By default, this will only call prompt_welcome to display basic information about the class itself
	 As a result, this function can also be overwritten to do something when this menu is entered
	 */
	virtual void entered() {
		prompt_welcome();
	}
	void prompt_welcome() const;

	/*
	 Test if this menu is null.
	 By "null", it means this menu is just initialized by a default constructor
	 */
	bool is_null() const {
		return (returnable && !auth && parent == 0 && desc == "" && info == "" && caption == "Untitled" && dir == "/" && cmd.empty() && para.empty());
	}

	/*
	 Test if two menus are equal
	 By "equal", it means two classes' full directories (directories and captions) are the same
	 */
	bool operator==(menu rhs) {
		return (this->dir == rhs.dir) && (this->caption == rhs.caption);
	}

};

#endif /* MENU_H_ */
