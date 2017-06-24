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
	Grid(std::string board, char player, char column);
	bool hasFirstWon();
	bool hasSecondWon();
	
	void print();

	private:
	bool checkAll(char, std::size_t);
	bool checkRows(char, std::size_t);
	bool checkCols(char, std::size_t);
	bool checkDiags(char, std::size_t);

	std::string cols[7];
	std::string rows[6];
	std::string diags[12];
};
#endif // GRID_HPP

