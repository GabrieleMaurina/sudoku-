#include "sudoku.h"

void sudoku::out(){
	f9(j){
		f9(i)cout<<((s[i][j].n)?(s[i][j].n):0)<<(i<8?" ":"");
		cout<<endl;
	}
}

bool sudoku::clear_c(const sint i, const sint j, const sint n){
	const sint x = i/3*3;
	const sint y = j/3*3;
	bool f = false;
	f9(k){
		if(k!=j) f = s[i][k].set_c(n, false) || f;
		if(k!=i) f = s[k][j].set_c(n, false) || f;
	}
	fg(k, w)if(x+k!=i && y+w!=j) f = s[x+k][y+w].set_c(n, false) || f;
	return f;
}

bool sudoku::clear_2(const sint x1, const sint y1, const sint x2, const sint y2){
	bool f = false;
	sint a, b;
	f19(i)if(s[x1][y1].c & square::conv[i] == square::conv[i]){a=i; break;}
	l(i,a+1,10,1)if(s[x1][y1].c & square::conv[i] == square::conv[i]){b=i; break;}
	f = clear_c(x1, y1, a) || f;
	f = clear_c(x1, y1, b) || f;
	f = clear_c(x2, y2, a) || f;
	f = clear_c(x2, y2, b) || f;
	return f;
}

bool sudoku::clear_row(const sint i, const sint j, const sint n){
	bool f = false;
	l1(x,i) f = s[x][j].set_c(n, false) || f;
	l(x,i+3,9,1) f = s[x][j].set_c(n, false) || f;
	return f;
}

bool sudoku::clear_col(const sint i, const sint j, const sint n){
	bool f = false;
	l1(y,j) f = s[i][y].set_c(n, false) || f;
	l(y,j+3,9,1) f = s[i][y].set_c(n, false) || f;
	return f;
}

void sudoku::init_from_istream(istream& is){
	char c;
	f9(j)f9(i){
		do is>>c;
		while(c<48 || c>57);
		if(c>48){;
			set_n(i, j, c-48);
		}
	}
}

void sudoku::init_from_stdin(){
	init_from_istream(cin);
}

void sudoku::init_from_file(const string& file){
	ifstream ifs;
	ifs.open(file);
	init_from_istream(ifs);
	ifs.close();
}
