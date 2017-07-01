#include "ValidatorGrid.hpp"

ValidatorGrid::ValidatorGrid(std::string board = "")
{
	mBoard = board;
	constexpr int size = 6*7;

	if(mBoard.length() > size) 
		throw;

	mBoard.append(size - mBoard.length(), '0');
	
}

bool ValidatorGrid::isValid()
{
	return (!hasBothPlayersWon() 
		&& !onePlayerPutTwoStonesOrMoreMore());
}

bool ValidatorGrid::hasBothPlayersWon()
{
	Grid grid(mBoard);
	return (grid.hasFirstWon() 
		&& grid.hasSecondWon());
}

bool ValidatorGrid::onePlayerPutTwoStonesOrMoreMore()
{
	// TODO: implement
	return false;
}

bool ValidatorGrid::stoneIsHanging()
{
	// TODO: implement
	return false;
}

