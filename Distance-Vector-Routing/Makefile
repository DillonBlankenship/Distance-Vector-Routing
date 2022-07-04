CFLAGS=-O3 -std=c++11

simulator: Edge.o Network.o Node.o DistanceVector.o Simulator.o
	g++ $(CFLAGS) Edge.o Network.o Node.o DistanceVector.o Simulator.o -o simulator

Edge.o: DV_Sim.h Edge.cpp
	g++ $(CFLAGS) -c Edge.cpp

Network.o: DV_Sim.h Network.cpp
	g++ $(CFLAGS) -c Network.cpp

Node.o: DV_Sim.h Node.cpp
	g++ $(CFLAGS) -c Node.cpp

DistanceVector.o: DV_Sim.h DistanceVector.cpp
	g++ $(CFLAGS) -c DistanceVector.cpp

Simulator.o: DV_Sim.h Simulator.cpp
	g++ $(CFLAGS) -c Simulator.cpp

.PHONY: clean
clean:
	rm -f Edge.o Network.o Node.o Simulator.o DistanceVector.o simulator
