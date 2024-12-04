#pragma once
#include "DEFS.h"

class CellPosition
{
	int vCell; // the vertical cell number: starts from 0 to NumVerticalCells - 1
	int hCell; // the horizontal cell number: starts from 0 to NumHorizontalCells - 1

public:
	CellPosition (); // Initializes the cell to (-1,-1) indicating not initialized with valid values
	CellPosition (int v, int h); // Sets vCell and hCell if valid
	CellPosition (int cellNum);  // Sets vCell and hCell from the passed cellNum if valid

	// Note: this class does NOT deal with real coordinates, it deals with the "vCell", "hCell" and "cellNum" instead

	// assuming NumVerticalCells = 5 and NumHorizontalCells = 11 
	// Cell Numbers (CellNum) should be from 1 to 55
	// Numbered from [left-to-right] [bottom-up], as follows:

	// hCell (right):   0    1   ...   10
	// vCell (below):
	//   0             C45  C46  ...  C55
	//   1             C34  C35  ...  C44
	//  ...            ...  ...  ...  ...
	//   3             C12  C13  ...  C22
	//   4             C1   C2   ...  C11

	// In the Grid above, C13 has vCell = 3 and hCell = 1
	

	
	bool SetVCell(int v); 		//DONE

	bool SetHCell(int h); 		//DONE

	int VCell() const; // The getter of vCell
	int HCell() const; // The getter of hCell


	bool IsValidCell() const;		//DONE
		
	int GetCellNum() const;   		//DONE

	static int GetCellNumFromPosition(const CellPosition & cellPosition);  		//DONE

	static CellPosition GetCellPositionFromNum(int cellNum);		//DONE

    void AddCellNum(int addedNum, Direction direction);		//DONE

};

