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

bool CellPosition::SetVCell(int v)
{
	if (IsValidCell){
		vCell = v;
		return true;
	}
	return false;

	///TODO: Implement this function as described in the .h file (don't forget the validation)

	 // this line sould be changed with your implementation



}

	


bool CellPosition::SetHCell(int h) 
{
	if (IsValidCell) {
		hCell = h;
		return true;
	}
	return false;
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	 // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >0 && hCell < NumHorizontalCells) {
		return true;
	} return false;



	///TODO: Implement this function as described in the .h file
	 // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int CellNum;
		
	if (!cellPosition.IsValidCell()) {
		return -1;
	}
	else {
		CellNum = (NumVerticalCells - cellPosition.vCell - 1) * NumHorizontalCells + cellPosition.hCell + 1;
	}


	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file

	return CellNum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	if (cellNum < 1 || cellNum > NumVerticalCells * NumHorizontalCells) {
		return position;
	}

	position.vCell = (NumVerticalCells - 1) - ((cellNum - 1) / NumHorizontalCells);



	position.hCell = (cellNum - 1) % NumHorizontalCells;



	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	// will implement when home
	/// TODO: Implement this function as described in the .h file


	// Note: this function updates the data members (vCell and hCell) of the calling object

}