# make/move required dependencies, targets for everything inside current directory

# glfw3 target (static lib)
.PHONY: glfw
glfw:
	if [ ! -d "./glfw/"]; then git submodule add https://github.com/glfw/glfw.git; fi;
	git submodule deinit -f ./glfw/
	git submodule update --init ./glfw/
	if [ -d "./glfw/build/" ]; then rm -rf ./glfw/build/; fi;
	mkdir ./glfw/build/ && cmake -S ./glfw/ -B ./glfw/build/
	cd ./glfw/build/ && make glfw
	if [ ! -d "../bin/GLFW/" ]; then mkdir -p ../bin/GLFW/; fi;
	cp ./glfw/build/src/libglfw3.a ../bin/GLFW/libglfw3.a
	if [ ! -d "../src/vendor/GLFW/" ]; then mkdir -p ../src/vendor/GLFW/; fi;
	cp ./glfw/include/GLFW/glfw3.h ../src/vendor/GLFW/glfw3.h

# glew target (static lib)
.PHONY: glew
glew:
	if [ ! -d "./glew/"]; then git submodule add https://github.com/nigels-com/glew.git; fi;
	git submodule deinit -f ./glew/
	git submodule update --init ./glew/
	cd ./glew/auto/ && make
	cd ./glew/ && make
	if [ ! -d "../bin/GLEW/" ]; then mkdir -p ../bin/GLEW/; fi;
	cp ./glew/lib/libGLEW.a ../bin/GLEW/libglew.a
	if [ ! -d "../src/vendor/GLEW/" ]; then mkdir -p ../src/vendor/GLEW/; fi;
	cp ./glew/include/GL/glew.h ../src/vendor/GLEW/glew.h
