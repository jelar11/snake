
P_NAME=snake
B_DIR=debug
S_DIR=src

OBJ=${B_DIR}/main.o

COMPILER_FLAGS = -g -Wall
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
# -lSDL2main -Wl,-Bdynamic -lpthread
DIRS_TO_SEARCH = -I S_DIR/include



# all: ${OBJ}
# #	mkdir ${B_DIR}
# 	${CXX} ${OBJ} ${COMPILER_FLAGS} ${DIRS_TO_SEARCH} ${LINKER_FLAGS} -o ${B_DIR}/${P_NAME}

# ${B_DIR}/main.o: ${S_DIR}/main.cpp ${S_DIR}/functions.h ${S_DIR}/global.h ${S_DIR}/LoadMedia.cpp
# 	${CXX} -c ${S_DIR}/main.cpp -o ${B_DIR}/main.o
#

all:
	$(CXX) ${S_DIR}/main.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${B_DIR}/${P_NAME}

setup:
	mkdir -p ${B_DIR}

clean:
	rm -Rf ${B_DIR}/*


run: all
	${B_DIR}/${P_NAME}