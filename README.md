# NetworkSimulator
#######
# Implements a multi-threaded link layer network simulator. 
The communication between end host objects is through a link object that supports full-duplex transfer of frames. 
The intermediate switch between hosts is a layer 2 switch that has a forwarding table which it updates based on the history. 
Basically, the forwarding table is a mapping between the MAC addresses of the hosts and the swithch outgoing interface.
The packets at the hosts are generated randomly according to the Poisson distribution to simulate a real network scenario. i.e.
the packet interarrival times are based on the exponential distribution and the packet sizes are from the uniform distribution. 
The operation of the switch is multi-threaded; once a host starts sending packets to the switch, it creates a new thread for each host and runs the interface separately. 
The access to the link interface is provided exclusively to a node through the mutex at the frame. 
To run, the hosts and the frames need to be defined in the main file; the packets received and sent from each hosts are saved in .txt 
files with the file name being the host names. 
#######
