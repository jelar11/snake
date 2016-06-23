
P_NAME=snake
B_DIR=debug
S_DIR=src

OBJ=LTimer.o


COMPILER_FLAGS = -g -Wall -Wunused
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
# -lSDL2main -Wl,-Bdynamic -lpthread
DIRS_TO_SEARCH = -I S_DIR


all: ${OBJ}
	$(CXX) ${COMPILER_FLAGS} ${S_DIR}/main.cpp ${LINKER_FLAGS} -o ${B_DIR}/${P_NAME} ${B_DIR}/LTimer.o


LTimer.o:
	${CXX} ${COMPILER_FLAGS} -c ${S_DIR}/LTimer/LTimer.cpp -o ${B_DIR}/LTimer.o


clean:
	rm -Rf ${B_DIR}/*
