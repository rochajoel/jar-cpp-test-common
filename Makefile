solution_src_cpp = $(wildcard src/*.cpp)
solution_obj_cpp = $(solution_src_cpp:.cpp=.o)

all: $(solution_obj_cpp)
	@echo All done!
	
$(solution_obj_cpp): %.o: %.cpp
	gcc -std=c++11 -c -o $@ $^

test:
	@echo Test Hello World!


