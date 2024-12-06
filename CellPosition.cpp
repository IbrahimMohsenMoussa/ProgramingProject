#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)	//DONE
{
	if (v >= 0 && v < NumVerticalCells){
		vCell = v;
		return true;
	}
	return false;

}

	


bool CellPosition::SetHCell(int h) 	//DONE
{
	if (h >= 0 && h < NumHorizontalCells) {
		hCell = h;
		return true;
	}
	return false;
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const	//DONE
{
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >=0 && hCell < NumHorizontalCells) {
		return true;
	} return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)	//DONE
{
	int CellNum;
		
	if (!cellPosition.IsValidCell()) {
		return -1;
	}
	else {
		CellNum = (NumVerticalCells - cellPosition.vCell - 1) * NumHorizontalCells + cellPosition.hCell + 1;
	}

	return CellNum;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)	//DONE
{
	CellPosition position;

	if (cellNum < 1 || cellNum > NumVerticalCells * NumHorizontalCells) {
		return position;
	}

	position.vCell = (NumVerticalCells - 1) - ((cellNum - 1) / NumHorizontalCells);



	position.hCell = (cellNum - 1) % NumHorizontalCells;

	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)	//DONE
{
	int cNum = GetCellNum();


	switch (direction) {

		case UP:
			cNum += addedNum * NumHorizontalCells;
			break;
		case DOWN:
			cNum -= addedNum * NumHorizontalCells;
			break;
		case RIGHT:
			cNum += addedNum;
			break;
		case LEFT:
			cNum -= addedNum;
			break;
	}

	if (cNum < 1) {
		cNum = 1;
	}
	else if (cNum > NumVerticalCells * NumHorizontalCells) {
		cNum = NumVerticalCells * NumHorizontalCells;
	}


	*this = GetCellPositionFromNum(cNum); //to directly update the data members



}