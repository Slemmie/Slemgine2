# targets for Slemgine2 along with everything required to build it

# default full release build
all: dependencies pch_release release

# all required dependencies that needs to be built
dependencies:
	cd ./vendor/ && make glfw
	cd ./vendor/ && make glew
	git submodule deinit -f .
	git submodule update --init

# general flags
CXX_FLAGS = -Wshadow -Wall -std=c++17
CXX_RELEASE_FLAGS = -O2 -DGLEW_STATIC
CXX_DEBUG_FLAGS = -g -fsanitize=undefined -D_GLIBCXX_DEBUG -DGLEW_STATIC
#CXX_DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DGLEW_STATIC

# universal options
INCLUDES = -I ./src/ -I ./src/vendor/
LINKS = -L ./bin/GLFW/ -lglfw3 -ldl -lGL -lpthread -L ./bin/GLEW/ -lglew
PCH_INCLUDES_RELEASE = -include ./bin/pch/release_slpch.h
PCH_INCLUDES_DEBUG = -include ./bin/pch/debug_slpch.h

# Slemgine2 precompiled header (release)
pch_release:
	if [ ! -d "./bin/pch/" ]; then mkdir -p ./bin/pch/; fi;
	g++ $(CXX_FLAGS) -fPIC ./src/pch/slpch.h -o ./bin/pch/release_slpch.h.gch \
	$(LINKS) $(CXX_RELEASE_FLAGS) $(HEADERS)

# Slemgine2 precompiled header (debug)
pch_debug:
	if [ ! -d "./bin/pch/" ]; then mkdir -p ./bin/pch/; fi;
	g++ $(CXX_FLAGS) -fPIC ./src/pch/slpch.h -o ./bin/pch/debug_slpch.h.gch \
	$(LINKS) $(CXX_RELEASE_FLAGS) $(HEADERS)

# all source files in Slemgine2 build
SOURCE_FILES = \
#./src/tmp_dummy.cpp

# required for individual source file builds
CXX_TRAILING_FLAGS = -DGLEW_STATIC

# targets for all source files in Slemgine2 build

#.PHONY: ./src/tmp_dummy.cpp
#./src/driver.cpp:
#	g++ $(CXX_FLAGS) -fPIC -c $@ $(LINKS) $(CXX_TRAILING_FLAGS) $(HEADERS)

# Slemgine2 release target
release:
	make prepare_release
	CXX_TRAIL_FLAGS_ARG="$(PCH_INCLUDES_RELEASE) $(CXX_RELEASE_FLAGS)"; \
	$(foreach file, $(SOURCE_FILES), make $(file) CXX_TRAILING_FLAGS="$${CXX_TRAIL_FLAGS_ARG}";)
	g++ $(CXX_FLAGS) -shared -o ./bin/libSlemgine2.so *.o $(LINKS) $(CXX_RELEASE_FLAGS)
	rm *.o

# Slemgine2 preperation and check for missing directories/files (release)
prepare_release:
	if [ ! -d "./bin/" ]; then mkdir -p ./bin/; fi;
	@if [ ! -d "./bin/GLFW/" ]; then echo "warning: missing directory 'bin/GLFW/'"; fi;
	@if [ ! -f "./bin/GLFW/libglfw3.a" ]; then echo "warning: missing file 'bin/GLFW/libglfw3.a'"; fi;
	@if [ ! -d "./bin/GLEW/" ]; then echo "warning: missing directory 'bin/GLEW/'"; fi;
	@if [ ! -f "./bin/GLEW/libglew.a" ]; then echo "warning: missing file 'bin/GLEW/libglew.a'"; fi;
	@if [ ! -d "./src/vendor/GLFW/" ]; then echo "warning: missing directory 'src/vendor/GLFW/'"; fi;
	@if [ ! -f "./src/vendor/GLFW/glfw3.h" ]; then echo "warning: missing file 'src/vendor/GLFW/glfw3.h'"; fi;
	@if [ ! -d "./src/vendor/GLEW/" ]; then echo "warning: missing directory 'src/vendor/GLEW/'"; fi;
	@if [ ! -f "./src/vendor/GLEW/glew.h" ]; then echo "warning: missing file 'src/vendor/GLEW/glew.h'"; fi;
	@if [ ! -d "./bin/pch/" ]; then echo "warning: missing directory 'bin/pch/'"; fi;
	@if [ ! -f "./bin/pch/release_slpch.h.gch" ]; then echo "warning: missing file 'bin/pch/release_slpch.h.gch"; fi;

# Slemgine2 debug target
debug:
	make prepare_debug
	CXX_TRAIL_FLAGS_ARG="$(PCH_INCLUDES_DEBUG) $(CXX_DEBUG_FLAGS)"; \
	$(foreach file, $(SOURCE_FILES), make $(file) CXX_TRAILING_FLAGS="$${CXX_TRAIL_FLAGS_ARG}";)
	g++ $(CXX_FLAGS) -shared -o ./bin/libSlemgine2_debug.so *.o $(LINKS) $(CXX_DEBUG_FLAGS)
	rm *.o

# Slemgine2 preperation and check for missing directories/files (debug)
prepare_debug:
	if [ ! -d "./bin/" ]; then mkdir -p ./bin/; fi;
	@if [ ! -d "./bin/GLFW/" ]; then echo "warning: missing directory 'bin/GLFW/'"; fi;
	@if [ ! -f "./bin/GLFW/libglfw3.a" ]; then echo "warning: missing file 'bin/GLFW/libglfw3.a'"; fi;
	@if [ ! -d "./bin/GLEW/" ]; then echo "warning: missing directory 'bin/GLEW/'"; fi;
	@if [ ! -f "./bin/GLEW/libglew.a" ]; then echo "warning: missing file 'bin/GLEW/libglew.a'"; fi;
	@if [ ! -d "./src/vendor/GLFW/" ]; then echo "warning: missing directory 'src/vendor/GLFW/'"; fi;
	@if [ ! -f "./src/vendor/GLFW/glfw3.h" ]; then echo "warning: missing file 'src/vendor/GLFW/glfw3.h'"; fi;
	@if [ ! -d "./src/vendor/GLEW/" ]; then echo "warning: missing directory 'src/vendor/GLEW/'"; fi;
	@if [ ! -f "./src/vendor/GLEW/glew.h" ]; then echo "warning: missing file 'src/vendor/GLEW/glew.h'"; fi;
	@if [ ! -d "./bin/pch/" ]; then echo "warning: missing directory 'bin/pch/'"; fi;
	@if [ ! -f "./bin/pch/debug_slpch.h.gch" ]; then echo "warning: missing file 'bin/pch/debug_slpch.h.gch"; fi;

# removes more or less anything build by this makefile + any leftover .o files
clean:
	existing_o=`ls -1 *.o 2>/dev/null | wc -l`; \
	if [ $$existing_o -ne 0 ]; then rm *.o; fi;
	if [ -d "./bin/" ]; then rm -rf ./bin; fi;
	if [ -d "./src/vendor/" ]; then rm -rf ./src/vendor/; fi;
