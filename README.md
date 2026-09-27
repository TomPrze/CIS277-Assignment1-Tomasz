# CIS-277 Assignment 1: Network Packet Buffer Pool

## Student
Tomasz Przewoznik
## Description
This assignment implements a simplified fixed-size memory pool that uses a Stack Abstract Data Type (ADT) to keep track of available memory blocks. MemoryPool creates a set of fixed size memory blocks and uses a custom Stack class to keep track of available blocks.
## Stack Implementation
I used Vector, because the professor recommended that the class use it.
## How to Compile
g++ main.cpp MemoryPool.cpp -o packetpool
## How to Run
./packetpool
## Analysis Questions
1. It can quickly release and get new blocks using LIFO (Last In, First Out).
2. allocate() returns nullptr since there are no blocks left.
3. So that it can become available again for allocation and to save memory by reusing the block.
4. It would put the block into the free stack twice, which would cause errors.
5. O(1), because it only checks if the stack is empty before taking a block.
6. O(n), because it has to look through the list of allocated blocks to find the pointer.
