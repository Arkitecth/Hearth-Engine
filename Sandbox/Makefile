CXX=g++
FILES=$(shell find . -name "*.cpp")
ENGINE_DIR=../Engine/
INC_DIR=-I$(ENGINE_DIR)
LINK_DIR=-L$(ENGINE_DIR)
LIBS=-lhearthEngine `pkg-config -cflags -libs sdl3`
EXE=sandbox

main: 
	$(CXX) $(FILES) $(INC_DIR) $(LINK_DIR) $(LIBS) -Wl,-rpath,@loader_path/$(ENGINE_DIR) -o $(EXE) 

clean:
	rm *.o
