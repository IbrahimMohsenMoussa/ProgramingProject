#include "Input.h"
#include <stdlib.h>
#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window *pW)
{
	pWind = pW; // point to the passed window
}

//////////////////////////////////////////////////////////////////////////////////////////

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

//////////////////////////////////////////////////////////////////////////////////////////

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27) // ESCAPE key is pressed
			return ""; // returns nothing as user has cancelled label
		if (Key == 13) // ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1)) // BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int Input::GetInteger(Output *pO) const
{

	string l_string = GetSrting(pO);
	if (l_string.empty()) {
		
		return 0; 
	}
	return stoi(l_string);


}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// [1] Toolbar clicks
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int clickedItemOrder = (x / UI.MenuItemWidth);
			switch (clickedItemOrder)
			{
			case ITM_SET_FLAG_CELL:
				return SET_FLAG_CELL;
			case ITM_ADD_ANTENNA:
				return ADD_ANTENNA;
			case ITM_ADD_BELT:
				return ADD_BELT;
			case ITM_ADD_WATER_PIT:
				return ADD_WATER_PIT;
			case ITM_ADD_DANGER_ZONE:
				return ADD_DANGER_ZONE;
			case ITM_ADD_WORKSHOP:
				return ADD_WORKSHOP;
			case ITM_COPY:
				return COPY;
			case ITM_CUT:
				return CUT;
			case ITM_PASTE:
				return PASTE;
			case ITM_DELETE:
				return DEL;
			case ITM_SAVE_GRID:
				return SAVE_GRID;
			case ITM_LOAD_GRID:
				return LOAD_GRID;
			case ITM_SWITCH_TO_PLAY_MODE:
				return TO_PLAY_MODE;
			case ITM_EXIT:
				return EXIT;
			default:
				return EMPTY;
			}
		}

		// [2] Grid area clicks
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return GRID_AREA;

		// [3] Status bar clicks
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)
	{
		// [1] Toolbar clicks in Play Mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int clickedItemOrder = (x / UI.MenuItemWidth);
			switch (clickedItemOrder)
			{
			case ITM_SELECT_COMMAND:
				return SELECT_COMMAND;
			case ITM_EXECUTE_COMMANDS:
				return EXECUTE_COMMANDS;
			case ITM_SWITCH_TO_DESIGN_MODE:
				return TO_DESIGN_MODE;
			case ITM_EXIT_PLAY_MODE:
				return EXIT;
			case ITM_REBOOT_REPAIR:
				return REBOOT_REPAIR;
			case ITM_NEW_GAME:
				return NEW_GAME;
			case ITM_USE_CONSUMABLE:
				return USE_CONSUMABLE;
			default:
				return EMPTY;
			}
		}

		// [2] Grid area clicks
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return GRID_AREA;

		// [3] Status bar clicks
		return STATUS;
	}

	return EMPTY; // Default return for undefined behavior
}

//////////////////////////////////////////////////////////////////////////////////////////

CellPosition Input::GetCellClicked() const
{
	CellPosition cellPos;
	if (UI.InterfaceMode == MODE_PLAY) {
		int x, y;
		pWind->WaitMouseClick(x, y); // Get the coordinates of the user click

		// Default CellPosition with invalid values (-1, -1)

		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			int hCell = x / UI.CellWidth;
			int vCell = (y - UI.ToolBarHeight) / UI.CellHeight;

			if (hCell >= 0 && hCell < NumHorizontalCells && vCell >= 0 && vCell < NumVerticalCells)
			{
				cellPos.SetHCell(hCell);
				cellPos.SetVCell(vCell);
			}
		}
	}
	return cellPos; // If the click is outside the grid, returns invalid (-1, -1)
}

//////////////////////////////////////////////////////////////////////////////////////////

int Input::GetSelectedCommandIndex() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	if ((y >= UI.height - UI.StatusBarHeight - UI.CommandsBarHeight - UI.AvailableCommandsYOffset) && (y < UI.height - UI.StatusBarHeight))
	{
		if (x < UI.AvailableCommandsXOffset || x > UI.AvailableCommandsXOffset + (UI.CommandItemWidth / 2) * MaxAvailableCommands)
			return -1;

		return (x - UI.AvailableCommandsXOffset) / (UI.CommandItemWidth / 2);
		;
	}

	return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////
