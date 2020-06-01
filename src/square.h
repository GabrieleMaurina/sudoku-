#ifndef SQUARE_H
#define SQUARE_H

#include "utils.h"

struct square{
	static const ssint conv[10];
	static const ssint conv_n[10];
	
	sint n = 0;
	sint c_n = 9;
	ssint c = 1022;
	
	inline sint get(){
		f19(i)if(c == conv[i]) return i;
		return 0;
	}

	inline bool get_c(const sint i){
		return c & conv[i];
	}

	inline bool set_c(const sint i, const bool v){
		if (v){
			if(!get_c(i)){
				++c_n;
				c |= conv[i];
				return true;
			}
		}
		else{
			if(get_c(i)){
				--c_n;
				c &= conv_n[i];
				return true;
			}
		}
		return false;
	}
};

#endif
