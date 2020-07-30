OBS_build: ObstacleMap.o Map2D.o main.o 
	g++ -o OBS_build ObstacleMap.o Map2D.o main.o 

ObstacleMap.o: ObstacleMap.cpp ObstacleMap.h
	g++ -c ObstacleMap.cpp

Map2D.o: Map2D.cpp Map2D.h
	g++ -c Map2D.cpp

main.o: main.cpp
	g++ -c main.cpp

