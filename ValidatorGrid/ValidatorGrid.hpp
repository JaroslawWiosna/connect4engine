#ifndef VALIDATORGRID_HPP
#define VALIDATORGRID_HPP

#include "Grid.hpp"
#include<string>

class ValidatorGrid{
	public:
	ValidatorGrid(std::string board);
	bool isValid();

	private:
	std::string mBoard;
	bool hasBothPlayersWon();
	bool onePlayerPutTwoStonesOrMoreMore();
	bool stoneIsHanging();
};

#endif // VALIDATORGRID_HPP
