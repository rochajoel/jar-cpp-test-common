solution_src_cpp := $(wildcard src/*.cpp)
solution_obj_cpp := $(solution_src_cpp:.cpp=.o)

$(solution_obj_cpp): %.o: %.cpp
	gcc -o $@ $<

all: $(solution_obj_cpp)
	@echo src: $(solution_src_cpp)
	@echo dst: $(solution_obj_cpp)
	@echo All done!

test:
	echo Test Hello World!


