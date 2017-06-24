#include "Grid.hpp"

Grid::Grid(std::string board = "")
{
	constexpr int size = 6*7;

	if(board.length() > size) 
		throw;

	board.append(size - board.length(), '0');

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

Grid::Grid(std::string board, char player, char column)
{

	Grid tmp(board);

}

bool Grid::hasFirstWon()
{
	return checkAll('1',4);
}

bool Grid::hasSecondWon()
{

	return checkAll('2',4);
}

bool Grid::checkAll(char player, std::size_t howMany)
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
