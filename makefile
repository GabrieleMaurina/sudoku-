all: sudoku demo

sudoku: src/sudoku++.cpp src/square.h src/square.cpp src/sudoku.h src/sudoku.cpp src/sudoku_solver.cpp
	g++ -o sudoku src/sudoku++.cpp src/square.cpp src/sudoku.cpp src/sudoku_solver.cpp

demo: src/demo.cpp src/square.h src/square.cpp src/sudoku.h src/sudoku.cpp src/sudoku_solver.cpp
	g++ -o demo src/demo.cpp src/square.cpp src/sudoku.cpp src/sudoku_solver.cpp

clean:
	rm -f sudoku demo
