#include "Grid.hpp"

Grid::Grid(std::string board = "") 
{
	mSymbolFirstPlayer = '1';
	mSymbolSecondPlayer = '2';

	mBoard = board;
	constexpr int size = 6*7;

	if(mBoard.length() > size) 
		throw;

	mBoard.append(size - mBoard.length(), '0');
	
	updateColsRowsDiags(mBoard);
}

Grid::Grid(std::string board, char player, unsigned int column)
{
	mBoard = board;
	constexpr int size = 6*7;
	if(mBoard.length() > size) 
		throw;

	mBoard.append(size - mBoard.length(), '0');
	
	Grid tmp(mBoard);
	if(tmp.isColumnFull(column))
		throw;

	//TODO: putStone - ?

	for (unsigned int i = 0; i < 6; ++i) {
		if (mBoard[i*7 + column] == '0') {
			mBoard[i*7 + column] = player;
			break;
		}
	}
	updateColsRowsDiags(mBoard);
}

bool Grid::hasFirstWon()
{
	return checkSequence('1',4);
}

bool Grid::hasSecondWon()
{

	return checkSequence('2',4);
}

bool Grid::checkSequence(char player, std::size_t howMany)
{
	return (checkRows(player, howMany) 
		|| checkCols(player, howMany) 
		|| checkDiags(player, howMany));
}

bool Grid::checkRows(char player, std::size_t howMany)
{
	std::string winningPattern{};
	winningPattern.append(howMany, player);

	for (int i=0 ; i < 6 ; ++i) {
		if(rows[i].find(winningPattern) != std::string::npos) {
			return true;
		}
	}
	return false;
}
bool Grid::checkCols(char player, std::size_t howMany)
{
	std::string winningPattern{};
	winningPattern.append(howMany, player);

	for (int i=0 ; i < 7 ; ++i) {
		if(cols[i].find(winningPattern) != std::string::npos) {
			return true;
		}
	}
	return false;
}
bool Grid::checkDiags(char player, std::size_t howMany)
{
	std::string winningPattern{};
	winningPattern.append(howMany, player);

	for (int i=0 ; i < 12 ; ++i) {
		if(diags[i].find(winningPattern) != std::string::npos) {
			return true;
		}
	}
	return false;
}

void Grid::print()
{
	for (int i=5 ; i >= 0 ; --i)
	{
		std::cout << i << "...";
		std::cout << rows[i] << std::endl;
	}
	std::cout << std::endl;

	char c = 'A';
	for (int i=0 ; i < 7 ; ++i)
	{
		std::cout << static_cast<char>(c+i) << "...";
		std::cout << cols[i] << std::endl;
	}
	std::cout << std::endl;


}

void Grid::updateColsRowsDiags(std::string board)
{
	for (int i=0 ; i < 6 ; ++i)
		rows[i] = board.substr(7*i, 7);	

	for (int i=0 ; i < 6 ; ++i)
		for (int j=0 ; j < 7 ; ++j)
			cols[j].push_back(rows[i][j]);

	//dirty :(
	diags[0].push_back(rows[2][0]);
	diags[0].push_back(rows[3][1]);
	diags[0].push_back(rows[4][2]);
	diags[0].push_back(rows[5][3]);

	diags[1].push_back(rows[1][0]);
	diags[1].push_back(rows[2][1]);
	diags[1].push_back(rows[3][2]);
	diags[1].push_back(rows[4][3]);
	diags[1].push_back(rows[5][4]);

	diags[2].push_back(rows[0][0]);
	diags[2].push_back(rows[1][1]);
	diags[2].push_back(rows[2][2]);
	diags[2].push_back(rows[3][3]);
	diags[2].push_back(rows[4][4]);
	diags[2].push_back(rows[5][5]);

	diags[3].push_back(rows[0][1]);
	diags[3].push_back(rows[1][2]);
	diags[3].push_back(rows[2][3]);
	diags[3].push_back(rows[3][4]);
	diags[3].push_back(rows[4][5]);
	diags[3].push_back(rows[5][6]);

	diags[4].push_back(rows[0][2]);
	diags[4].push_back(rows[1][3]);
	diags[4].push_back(rows[2][4]);
	diags[4].push_back(rows[3][5]);
	diags[4].push_back(rows[4][6]);

	diags[5].push_back(rows[0][3]);
	diags[5].push_back(rows[1][4]);
	diags[5].push_back(rows[2][5]);
	diags[5].push_back(rows[3][6]);
	///

	diags[6].push_back(rows[2][6]);
	diags[6].push_back(rows[3][5]);
	diags[6].push_back(rows[4][4]);
	diags[6].push_back(rows[5][3]);

	diags[7].push_back(rows[1][6]);
	diags[7].push_back(rows[2][5]);
	diags[7].push_back(rows[3][4]);
	diags[7].push_back(rows[4][3]);
	diags[7].push_back(rows[5][2]);

	diags[8].push_back(rows[0][6]);
	diags[8].push_back(rows[1][5]);
	diags[8].push_back(rows[2][4]);
	diags[8].push_back(rows[3][3]);
	diags[8].push_back(rows[4][2]);
	diags[8].push_back(rows[5][1]);

	diags[9].push_back(rows[0][5]);
	diags[9].push_back(rows[1][4]);
	diags[9].push_back(rows[2][3]);
	diags[9].push_back(rows[3][2]);
	diags[9].push_back(rows[4][1]);
	diags[9].push_back(rows[5][0]);

	diags[10].push_back(rows[0][4]);
	diags[10].push_back(rows[1][3]);
	diags[10].push_back(rows[2][2]);
	diags[10].push_back(rows[3][1]);
	diags[10].push_back(rows[4][0]);

	diags[11].push_back(rows[0][3]);
	diags[11].push_back(rows[1][2]);
	diags[11].push_back(rows[2][1]);
	diags[11].push_back(rows[3][0]);
}

bool Grid::isColumnFull(unsigned int column)
{
	if (cols[column][5] == '0')
		return false;
	else
		return true;
}

unsigned int Grid::columnLevel(unsigned int colNumber)
{
	for (int i=5; i>=0; --i) {
		if (cols[colNumber-1][i] != '0') {
			return (i+1);
		}
	}
	
	throw;
}

