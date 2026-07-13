CXX=g++
FILES=$(shell find . -name "*.cpp")
DYLD_LIB=libhearthEngine.dylib
FLAGS=-dynamiclib -install_name @rpath/$(DYLD_LIB)

$(DYLD_LIB):
	$(CXX) $(FLAGS) $(FILES) -o $(DYLD_LIB)
clean:
	rm $(DYLD_LIB)
