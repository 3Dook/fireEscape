#Makefile

PROJ = FINALPROJECT_DOAN_DUC
OUT = final
CXX = g++
CXXFLAGS = -g -std=c++11

OBJS = main.o menu.o dlink.o door.o fire.o floor.o grid.o item.o key.o mystery.o player.o space.o wall.o

SRCS = main.cpp menu.cpp dlink.cpp door.cpp fire.cpp floor.cpp grid.cpp item.cpp key.cpp mystery.cpp player.cpp space.cpp wall.cpp

HEADERS = menu.hpp dlink.hpp space.hpp door.hpp fire.hpp floor.hpp grid.hpp item.hpp key.hpp mystery.hpp player.hpp wall.hpp

${OUT}: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ${OUT}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile
clean:
	rm *.o ${OUT}

