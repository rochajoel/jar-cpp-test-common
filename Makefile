solution_src_cpp := $(wildcard *.cpp)
solution_obj_cpp := $(subst %.cpp, %.o, $(solution_src_cpp))

$(solution_obj_cpp): %.o: %.cpp
	gcc -o $@ $<

all: $(solution_obj_cpp)
	@echo src: $(solution_src_cpp)
	@echo dst: $(solution_obj_cpp)
	@echo All done!

test:
	echo Test Hello World!


