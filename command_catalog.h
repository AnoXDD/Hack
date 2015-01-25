/*
 * command_catelog.h
 *
 * This class contains information about every command that the
 * player will use during the game.
 *
 *  Created on: May 20, 2014
 *      Author: Anoxic
 */

#ifndef COMMAND_CATELOG_H_
#define COMMAND_CATELOG_H_

#include <map>
#include <string>

class command_catalog {
	// This is the map containing instructions of each command
	std::map<std::string, std::string> command;
	void init();
public:
	command_catalog() {
		init();
	}
	/*
	 Return the instructions of the command (with ": " prefixed)
	 Return an empty string if such command is not found
	 */
	const std::string operator[](const std::string&) const;
};

#endif /* COMMAND_CATELOG_H_ */
