COMPILATEUR = clang++
SOURCE_LIBS = -Ilib/
OSX_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
OSX_OUT = -o "bin/build_osx"
CFILES = src/*.cpp

build_osx :
	$(COMPILATEUR) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT)