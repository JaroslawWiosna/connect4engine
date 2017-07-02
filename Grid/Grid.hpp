#ifndef GRID_HPP
#define GRID_HPP

#include<iostream>
//#include<utility> // pair
#include<list> 
#include<vector> 
#include<string> 
#include<cstdint>

class Grid{
	public:
	Grid(std::string board);
	Grid(std::string board, char player, unsigned int column);
	bool hasFirstWon();
	bool hasSecondWon();
	bool hasPlayerWon(unsigned int);
	bool hasPlayerWon(char);
	std::string getBoard();
	unsigned int columnLevel(unsigned int);
	unsigned int findNextWinningMove(char);
	
	void print();

	private:
	bool checkSequence(char, std::size_t);
	bool checkRows(char, std::size_t);
	bool checkCols(char, std::size_t);
	bool checkDiags(char, std::size_t);
	void updateColsRowsDiags(std::string board);
	bool isColumnFull(unsigned int);

	std::string mBoard;
	char mSymbolFirstPlayer;
	char mSymbolSecondPlayer;
	std::string cols[7];
	std::string rows[6];
	std::string diags[12];
};
#endif // GRID_HPP

