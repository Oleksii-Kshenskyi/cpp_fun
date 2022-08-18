SRC_DIR=src
CXXFLAGS=-std=c++20 -DNDEBUG -O3
INCLUDES=-I./${SRC_DIR}
NAME=-o funcex


all: ./${SRC_DIR}/main.cxx
	g++ ${CXXFLAGS} ${INCLUDES} ${NAME} ./${SRC_DIR}/main.cxx 