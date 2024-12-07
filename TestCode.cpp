#include "Input.h"
#include "Output.h"
// BACK UP BRANCH

// This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	// Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	// Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:
	//			- Create The FULL Tool bar of Design Mode, the grid area, the status bar
	//				and an empty command bar
	//			- This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid, Status bar and Empty Command bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 1.1- Drawing the Command bar in the Game mode
	// =============================================
	pOut->PrintMessage("1.1- Drawing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	Command savedCommands1[5];
	for (int i = 0; i < 5; i++)
		savedCommands1[i] = NO_COMMAND;
	Command availableCommands1[10];
	for (int i = 0; i < 10; i++)
		availableCommands1[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands1, 5, availableCommands1, 10);
	pOut->PrintMessage("1.1.1- Finished Drawing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.2- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TESTING 4 SAVED COMMANDS AND 4 AVAILABLE COMMANDS

	Command savedCommands2[4];
	for (int i = 0; i < 4; i++)
		savedCommands2[i] = NO_COMMAND;
	Command availableCommands2[4];
	for (int i = 0; i < 4; i++)
		availableCommands2[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands2, 4, availableCommands2, 4);

	pOut->PrintMessage("1.1.2- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.3- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// TESTING 4 SAVED COMMANDS (move forward once first card) AND 4 AVAILABLE COMMANDS (no command first card)

	Command savedCommands3[4];
	savedCommands3[0] = MOVE_FORWARD_ONE_STEP;
	for (int i = 1; i < 4; i++)
		savedCommands3[i] = NO_COMMAND;

	Command availableCommands3[4];
	availableCommands3[0] = NO_COMMAND;
	for (int i = 1; i < 4; i++)
		availableCommands3[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands3, 4, availableCommands3, 4);

	pOut->PrintMessage("1.1.3- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.4- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click
	

	// TESTING 5 SAVED COMMANDS (move forward twice first card) AND 6 AVAILABLE COMMANDS (no command first card)

	Command savedCommands4[5];
	savedCommands4[0] = MOVE_FORWARD_TWO_STEPS;
	for (int i = 1; i < 5; i++)
		savedCommands4[i] = NO_COMMAND;
	
	Command availableCommands4[6];
	availableCommands4[0] = NO_COMMAND;
	for (int i = 1; i < 6; i++)
		availableCommands4[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands4, 5, availableCommands4, 6);

	pOut->CreateDesignModeToolBar();

	pOut->PrintMessage("1.1.4- Finished Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.1- Drawing Water Pits Cells //
	// =============================

	pOut->PrintMessage("2.1- Drawing (Water Pits Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_10(10); // cell num 10
	CellPosition cell_53(53); // cell num 53
	CellPosition cell_1(1);	  // cell num 1

	// Testing Water Pits in cell_10 and cell_53 and cell_1 (Invalid)

	pOut->DrawWaterPit(cell_10);
	pOut->DrawWaterPit(cell_53);
	pOut->DrawWaterPit(cell_1);

	pOut->PrintMessage("FINISHED - Drawing (Water Pits) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.2- Drawing DangerZone Cells //
	// =============================
	pOut->PrintMessage("2.2- Drawing (DangerZone Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_20(20); // cell num 20
	CellPosition cell_60(60); // cell num 60

	// Testing DangerZone in cell_20, [cell_60 and cell_1] (Invalid)

	pOut->DrawDangerZone(cell_20);
	pOut->DrawDangerZone(cell_60);
	pOut->DrawDangerZone(cell_1);

	pOut->PrintMessage("FINISHED - Drawing (DangerZone) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.3- Drawing Players Test //
	// =========================
	pOut->PrintMessage("2.3- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition player_1(1);
	CellPosition player_2(2);
	CellPosition player_15(2, 18);
	CellPosition player_99(2, 5);

	/// Testing DrawPlayer function with 3 valid calls and 4 invalid calls

	pOut->DrawPlayer(player_1, 0, UI.PlayerColors[0], RIGHT);			//VALID
	pOut->DrawPlayer(player_1, 1, UI.PlayerColors[1], UP);				//VALID
	pOut->DrawPlayer(player_1, 2, UI.PlayerColors[2], DOWN);			
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[3], LEFT);
	pOut->DrawPlayer(player_15, 0, UI.PlayerColors[0], LEFT);
	pOut->DrawPlayer(player_99, 1, UI.PlayerColors[1], UP);				//VALID
	pOut->DrawPlayer(player_99, 5, UI.PlayerColors[1], DOWN);
	pOut->DrawPlayer(player_99, -1, UI.PlayerColors[1], LEFT);

	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 2.4- Drawing Flags
	/// ====================
	///
	pOut->PrintMessage("2.4- Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition flag_1(9);
	CellPosition flag_60(60);
	CellPosition flag_99(99);

	// Testing Flags in cell positions (flag_1, flag_60, flag_99)
	pOut->DrawFlag(flag_1);
	pOut->DrawFlag(flag_60);
	pOut->DrawFlag(flag_99);

	pOut->PrintMessage("FINISHED - Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 2.5- Drawing Belts
	/// ====================
	///
	pOut->PrintMessage("2.5- Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition belt_start_1(1);
	CellPosition belt_end_1(5);
	CellPosition belt_start_2(12);
	CellPosition belt_end_2(45);
	CellPosition belt_start_3(54);
	CellPosition belt_end_3(32);
	CellPosition belt_end_4(33);

	//	Testing drawing Belts with 3 valid calls and 3 invalid calls

	pOut->DrawBelt(belt_start_1, belt_end_1);		//VALID
	pOut->DrawBelt(belt_start_2, belt_end_2);		//VALID
	pOut->DrawBelt(belt_start_3, belt_end_3);		//VALID
	pOut->DrawBelt(belt_start_3, belt_end_4);
	pOut->DrawBelt(belt_start_1, belt_end_2);
	pOut->DrawBelt(belt_start_3, belt_end_4);

	pOut->PrintMessage("FINISHED - Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.6- Drawing Rotating Gears //
	// ===========================

	pOut->PrintMessage("2.6- Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_13(13);
	CellPosition cell_19(19);

	//	Testing drawing gears in clockwise and anticlockwise position


	pOut->DrawRotatingGear(cell_13, 0);
	pOut->DrawRotatingGear(cell_19, 1); 

	pOut->PrintMessage("FINISHED - Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.7- Drawing Antenna //
	// ======================
	pOut->PrintMessage("2.7- Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_25(25);

	pOut->DrawAntenna(cell_25); // Testing Antenna in cell position (cell_25)

	pOut->PrintMessage("FINISHED - Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.8- Drawing Workshop //
	// =======================

	pOut->PrintMessage("2.8- Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cell_30(30);

	pOut->DrawWorkshop(cell_30); // Testing Workshop in cell position (cell_30)

	pOut->PrintMessage("FINISHED - Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3:
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("Please enter an Integer, then press enter: ");
	int input = pIn->GetInteger(pOut);

	pOut->PrintMessage("You have entered: " + to_string(input));

	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click


	for (int i = 0; i < 5; i++)
	{
		CellPosition position = pIn->GetCellClicked();
	
		pOut->PrintMessage("You clicked the cell (" + to_string(position.VCell()) + ", " + to_string(position.HCell()) + ")");
	}

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("Please write a string, then press enter: ");

	string inputString = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();

	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("You have entered: " + inputString);

	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	CellPosition cellpos_1(0, 0);

	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter an integer for vCell (" + to_string(i + 1) + "/5):");

		pIn->GetPointClicked(x, y);

		int inputVInt = pIn->GetInteger(pOut);

		cellpos_1.SetVCell(inputVInt);

		pOut->PrintMessage("Now the vCell = " + to_string(cellpos_1.VCell()));

		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("SetHCell test, click to continue");
	pIn->GetPointClicked(x, y); // Wait for user to click before starting the next test

	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter an integer for hCell (" + to_string(i + 1) + "/5):");

		pIn->GetPointClicked(x, y);

		int inputHInt = pIn->GetInteger(pOut);

		cellpos_1.SetHCell(inputHInt);

		pOut->PrintMessage("Now the hCell = " + to_string(cellpos_1.HCell()));

		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y); 


	int l_V;
	int l_H;
	for (int i = 0; i < 5; i++)
	{

		pOut->PrintMessage("Enter an integer for vCell (" + to_string(i + 1) + "/5):");

		l_V = pIn->GetInteger(pOut);

		pIn->GetPointClicked(x, y);

		pOut->PrintMessage("Enter an integer for HCell (" + to_string(i + 1) + "/5):");

		pIn->GetPointClicked(x, y);

		l_H = pIn->GetInteger(pOut);

		CellPosition cellPos_t4(l_V, l_H);

		pOut->PrintMessage("The corresponding Cell Number is " + to_string(cellPos_t4.GetCellNum()));

		pIn->GetPointClicked(x, y); 
	}
	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	for (int i = 0; i < 5; i++)
	{

		pOut->PrintMessage("Enter an integer for the Cell Number (" + to_string(i + 1) + "/5):");

		pIn->GetPointClicked(x, y);

		int cellNum = pIn->GetInteger(pOut);

		CellPosition cellPos(cellNum);

		int vCell = cellPos.VCell(); 
		int hCell = cellPos.HCell(); 

		pOut->PrintMessage("This Cell has vCell = " + to_string(vCell) + ", hCell = " + to_string(hCell));

		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	pOut->PrintMessage("4.4- (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	for (int i = 0; i < 4; i++)
	{

		pOut->PrintMessage("Enter an integer for the Cell Number: (" + to_string(i + 1) + "/4):");

		pIn->GetPointClicked(x, y);

		int cellNum = pIn->GetInteger(pOut);

		pOut->PrintMessage("Enter an integer to be added to this Cell: (" + to_string(i + 1) + "/4):");

		pIn->GetPointClicked(x, y);

		int addedNum = pIn->GetInteger(pOut);

		CellPosition cellPos(cellNum);

		cellPos.AddCellNum(addedNum,(Direction)(i)); //Testing for all four directions

		int vCell = cellPos.VCell();
		int hCell = cellPos.HCell();

		pOut->PrintMessage("After adding, the Cell has vCell = " + to_string(vCell) + ", hCell = " + to_string(hCell));

		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y); // Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5:
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5:
	//         Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////

	pOut->CreateDesignModeToolBar();
	do
	{
		ActType = pIn->GetUserAction();

		int clickedCommandItemIndex; // if the action is SELECT_COMMAND, this will have the icon index
		switch (ActType)
		{
		// Design Mode Actions
		case SET_FLAG_CELL:
			pOut->PrintMessage("Action: SET_FLAG_CELL, Click anywhere");
			break;
		case ADD_ANTENNA:
			pOut->PrintMessage("Action: ADD_ANTENNA, Click anywhere");
			break;
		case ADD_BELT:
			pOut->PrintMessage("Action: ADD_BELT, Click anywhere");
			break;
		case ADD_WATER_PIT:
			pOut->PrintMessage("Action: ADD_WATER_PIT, Click anywhere");
			break;
		case ADD_DANGER_ZONE:
			pOut->PrintMessage("Action: ADD_DANGER_ZONE, Click anywhere");
			break;
		case ADD_WORKSHOP:
			pOut->PrintMessage("Action: ADD_WORKSHOP, Click anywhere");
			break;
		case COPY:
			pOut->PrintMessage("Action: COPY, Click anywhere");
			break;
		case CUT:
			pOut->PrintMessage("Action: CUT, Click anywhere");
			break;
		case PASTE:
			pOut->PrintMessage("Action: PASTE, Click anywhere");
			break;
		case DEL:
			pOut->PrintMessage("Action: DELETE, Click anywhere");
			break;
		case SAVE_GRID:
			pOut->PrintMessage("Action: SAVE_GRID, Click anywhere");
			break;
		case LOAD_GRID:
			pOut->PrintMessage("Action: LOAD_GRID, Click anywhere");
			break;
		case TO_PLAY_MODE:
			pOut->PrintMessage("Action: TO_PLAY_MODE, Switching to Play Mode");
			pOut->CreatePlayModeToolBar();
			pOut->PrintPlayersInfo("Player 1: HP=10, Position=Start | Player 2: HP=10, Position=Start");
			break;

		// Play Mode Actions
		case EXECUTE_COMMANDS:
			pOut->PrintMessage("Action: EXECUTE_COMMANDS, Click anywhere");
			break;
		case SELECT_COMMAND:
			pOut->PrintMessage("Action: SELECT_COMMAND, Select a command");
			clickedCommandItemIndex = pIn->GetSelectedCommandIndex();
			pOut->PrintMessage("Action: SELECT_COMMAND " + to_string(clickedCommandItemIndex + 1) + ", Click anywhere");
			break;
		case USE_CONSUMABLE:
			pOut->PrintMessage("Action: USE_CONSUMABLE, Click anywhere");
			break;
		case REBOOT_REPAIR:
			pOut->PrintMessage("Action: REBOOT_REPAIR, Click anywhere");
			break;
		case NEW_GAME:
			pOut->PrintMessage("Action: NEW_GAME, Starting a new game");
			break;
		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE, Switching to Design Mode");
			pOut->CreateDesignModeToolBar();
			break;

		// General Actions
		case GRID_AREA:
			pOut->PrintMessage("Action: GRID_AREA, Click anywhere");
			break;
		case STATUS:
			pOut->PrintMessage("Action: STATUS, Click anywhere");
			break;
		case EXIT:
			pOut->PrintMessage("Exiting the program. Goodbye!");
			break;

		default:
			pOut->PrintMessage("Action: Unknown action, Click anywhere");
			break;
		}
	} while (ActType != EXIT);

	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);

	delete pIn;
	delete pOut;
	return 0;
}