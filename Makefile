CXX=g++
FILES=main.cpp
INC=`pkg-config -cflags -libs sdl3`
EXE=main

main:
	$(CXX) $(INC) $(FILES) -o $(EXE) 

clean:
	rm $(EXE) 
