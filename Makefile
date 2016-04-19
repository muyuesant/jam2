run: countSheep
	./countSheep
countSheep: countSheep.o
	g++ countSheep.o -o countSheep
countSheep.o: countSheep.cpp
	g++ -c countSheep.cpp

