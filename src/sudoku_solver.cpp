#include "sudoku.h"

bool sudoku::naked_single(){
	f9(i)f9(j){
		if(!s[i][j].n && s[i][j].c_n == 1){
			set_n(i, j, s[i][j].get());
			return true;
		}
	}
	return false;
}

bool sudoku::hidden_single(){
	bool r, c, g;
	sint x, y;
	f9(i)f9(j)f19(k){
		if(!s[i][j].n && s[i][j].get_c(k)){
			r = c = g = true;
			f9(w){
				if(j!=w && s[i][w].get_c(k)) c = false;
				if(i!=w && s[w][j].get_c(k)) r = false;
			}
			if(r||c){
				set_n(i, j, k);
				return true;
			}
			x=i/3*3;
			y=j/3*3;
			fg(w,z){
				if((x+w!=i || y+z!=j) && s[x+w][y+z].get_c(k)) g = false;
			}
			if(g){
				set_n(i, j, k);
				return true;
			}
		}
	}
	return false;
}

bool sudoku::naked_pair(){
	f9(i)f9(j)if(i!=j)f9(k){
		if(!s[i][k].n && !s[j][k].n && s[i][k].c == s[j][k].c && s[i][k].c_n == 2)
			if (clear_2(i,k,j,k)) return true;
		if(!s[k][i].n && !s[k][j].n && s[k][i].c == s[k][j].c && s[k][i].c_n == 2)
			if(clear_2(k,i,k,j)) return true;
	}
	l(i,0,9,3)l(j,0,9,3)
		l(x1,i,i+3,1)l(y1,j,j+3,1)
			l(x2,i,i+3,1)l(y2,j,j+3,1)
				if((x1!=x2 || y1!=y2) && !s[x1][y1].n && !s[x2][y2].n && s[x1][y1].c == s[x2][y2].c && s[x1][y1].c_n ==2)
					if(clear_2(x1,y1,x2,y2)) return true;
	return false;
}

bool sudoku::pointing_pair_triple(){
	bool r, c;
	l(i,0,9,3)l(j,0,9,3)
		l(x,i,i+3,1)l(y,j,j+3,1)
			f19(k)if(s[i][j].get_c(k)){
				r = c = true;
				fg(w,z){
					if(j+z != y && s[i+w][j+z].get_c(k)) r = false;
					if(i+w != y && s[i+w][j+z].get_c(k)) c = false;
				}
				if(r && clear_row(i, j, k)) return true;
				if(c && clear_col(i, j, k)) return true;
			}
	return false;
}

bool sudoku::solve(){
	sint i = 0;
	out();
	while(r && i < t_n)
		if((this->*t[i])()) i=0, cout<<(int)i<<endl;
		else ++i;
	out();
	return !r;
}
