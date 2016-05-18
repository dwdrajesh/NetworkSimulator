objects = Frame.o Host.o\
	  Node.o Switch.o Port.o main.o
CXXFlags = -std=gnu++11 -pthread -g 

run: $(objects)
	g++ -o $@ $(objects) -$(CXXFlags)

%.o: %.cpp
	g++ -c $^ -$(CXXFlags)

Frame.o:Frame.cpp Frame.h
Host.o:Host.cpp Host.h
Node.o:Node.cpp Node.h
Port.o:Port.cpp Port.h
Switch.o:Switch.cpp Switch.h

PHONY:clean
clean:
	rm -f *.o *~ *.h.gch



