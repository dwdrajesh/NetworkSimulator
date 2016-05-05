objects = Frame.o Host.o\
	  Node.o main.o
CXXFlags = -Wall -std=gnu++11
runSim: $(objects)
	g++ -o runSim $(objects) -std=gnu++11 -I.

Frame.o:Frame.h
Host.o:Host.h
Node.o:Node.h

PHONY:clean
clean:
	rm -f *.o 
