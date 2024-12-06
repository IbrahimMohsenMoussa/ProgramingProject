#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType
{
	// Design Mode Actions
	SET_FLAG_CELL,	 // Add a flag to the grid
	ADD_ANTENNA,	 // Add an antenna to the grid
	ADD_BELT,		 // Add a belt to the grid
	ADD_WATER_PIT,	 // Add a water pit to the grid
	ADD_DANGER_ZONE, // Add a danger zone to the grid
	ADD_WORKSHOP,	 // Add a workshop to the grid
	COPY,			 // Copy a game object
	CUT,			 // Cut a game object
	PASTE,			 // Paste a game object
	DEL,			 // Delete a game object
	SAVE_GRID,		 // Save the current grid
	LOAD_GRID,		 // Load a previously saved grid
	TO_PLAY_MODE,	 // Switch to Play Mode
	EXIT,			 // Exit the application

	// Play Mode Actions
	EXECUTE_COMMANDS, // Execute saved movement commands
	SELECT_COMMAND,	  // Select a movement command
	USE_CONSUMABLE,	  // Use a consumable item
	REBOOT_REPAIR,	  // Reboot and repair the robot
	NEW_GAME,		  // Start a new game
	TO_DESIGN_MODE,	  // Switch to Design Mode
	EXIT_PLAY_MODE,	  // Exit the application
					// General Actions
	GRID_AREA, // Click on the grid area
	STATUS,	   // Click on the status bar
	EMPTY	   // Click on an empty space or undefined area
};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,
	ROTATE_LEFT,
	ROTATE_RIGHT,
	USE_TOOLKIT,
	USE_HACK_DEVICE,
	COMMANDS_COUNT,
};

#endif