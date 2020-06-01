#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <fstream>
#include <string>
#include "square.h"
#include "utils.h"

struct sudoku{
	sint r = 81;
	square s[9][9];

	inline square* operator[](const sint i){
		return s[i];
	}
	inline void set_n(const sint i, const sint j, const sint n){
		if(!s[i][j].n) --r;
		s[i][j].n = n;
		s[i][j].c = 0;
		s[i][j].c_n = 0;
		clear_c(i, j, n);
	}

	void out();
	bool clear_c(const sint i, const sint j, const sint n);
	bool clear_2(const sint x1, const sint y1, const sint x2, const sint y2);
	bool clear_row(const sint i, const sint j, const sint n);
	bool clear_col(const sint i, const sint j, const sint n);

	void init_from_istream(istream& is);
	void init_from_stdin();
	void init_from_file(const string& file);

	bool naked_single();
	bool hidden_single();
	bool naked_pair();
	bool pointing_pair_triple();
	bool solve();

	bool (sudoku::*t[4])() = {&sudoku::naked_single, &sudoku::hidden_single, &sudoku::naked_pair, &sudoku::pointing_pair_triple};
	const sint t_n = 4;
};

#endif
