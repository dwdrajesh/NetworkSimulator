# NetworkSimulator
#######
# Implements a multi-threaded link layer network simulator. 
The communication between end host objects is through a link object that supports full-duplex transfer of frames. 
The intermediate switch between hosts is a layer 2 switch that has a forwarding table which it updates based on the history. 
Basically, the forwarding table is a mapping between the MAC addresses of the hosts and the switch outgoing interface.
The packets at the hosts are generated randomly according to the Poisson distribution to simulate a real network scenario, i.e.
the packet interarrival times are based on the exponential distribution and the packet sizes are from the uniform distribution. 
The operation of the switch is multi-threaded; once a host starts sending packets to the switch, it creates a new thread for each host and runs the interface separately. 
The access to the link interface is provided exclusively to a node through the mutex at the frame. 
To run the simulation, the hosts and the frames need to be defined in the main file; the packets received and sent from each hosts are saved in .txt 
files with the file name being the host names. 

  ---
  Network Simulator - Detailed Explanation

  This is a multi-threaded Layer 2 (Ethernet) network simulator written in C++. It simulates 4 hosts communicating through a central switch, with realistic Poisson-distributed packet timing.

  Architecture Diagram

                      ┌──────────────────────────────────────────────────┐
                      │                NETWORK TOPOLOGY                  │
                      └──────────────────────────────────────────────────┘

    ┌───────────┐   f1 (A2S) ──►   ┌──────────────────┐   ◄── f5 (X2S)   ┌───────────┐
    │   Alice   │ ════════════════► │                  │ ◄════════════════ │    Xyz    │
    │  (Host)   │   ◄── f2 (S2A)   │   Layer 2        │   f6 (S2X) ──►   │  (Host)   │
    │ Thread 1  │ ◄════════════════ │   SWITCH         │ ════════════════► │ Thread 3  │
    └───────────┘                   │                  │                   └───────────┘
         │                          │  Forwarding      │                        │
         │ sends to Bob             │  Table:          │             sends to Cde
         │                          │  MAC → Port      │                        │
    ┌───────────┐   f3 (B2S) ──►   │                  │   ◄── f7 (C2S)   ┌───────────┐
    │    Bob    │ ════════════════► │  (4 port threads)│ ◄════════════════ │    Cde    │
    │  (Host)   │   ◄── f4 (S2B)   │                  │   f8 (S2C) ──►   │  (Host)   │
    │ Thread 2  │ ◄════════════════ │                  │ ════════════════► │ Thread 4  │
    └───────────┘                   └──────────────────┘                   └───────────┘

    Communication pairs:  Alice ↔ Bob    |    Xyz ↔ Cde
    Full-duplex links:    2 Frames per link (one each direction)
    Total threads:        8 (4 host + 4 switch port)

  Class Hierarchy

           ┌──────────────┐
           │  Node (base) │
           └──────┬───────┘
             ┌────┴────┐
       ┌─────┴──┐  ┌───┴──────┐
       │  Host  │  │  Switch  │
       └────────┘  └──────────┘

       ┌─────────┐  has 2   ┌───────┐
       │  Port   │ ───────► │ Frame │  (outgoing + incoming)
       └─────────┘          └───────┘

  ---
#######
