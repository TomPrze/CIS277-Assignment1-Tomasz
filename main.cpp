#include <iostream>
#include <cstring>
#include "MemoryPool.h"
using namespace std;

int main()
{
	MemoryPool pool(512, 8);
	
	cout << "Network Packet Buffer Pool" << endl;
	cout << "Block Size:		" << pool.blockSize() << " bytes" << endl;
	cout << "Blocks:			" << pool.availableBlocks() + pool.allocatedBlocks() << endl;
	cout << "Total Capacity:	" << pool.capacity() << " bytes" << endl;
	cout << endl;
	
	void* packet1 = pool.allocate();
    void* packet2 = pool.allocate();
    void* packet3 = pool.allocate();

    cout << "Packet 1 allocated: " << packet1 << endl;
    cout << "Packet 2 allocated: " << packet2 << endl;
    cout << "Packet 3 allocated: " << packet3 << endl;
    cout << endl;

    cout << "Available blocks: " << pool.availableBlocks() << endl;
    cout << "Allocated blocks: " << pool.allocatedBlocks() << endl;
    cout << endl;

	unsigned char packet[] =
    {
        0x45, 0x00, 0x00, 0x3C,
        0xAB, 0xCD, 0x12, 0x34
    };

    memcpy(packet1, packet, sizeof(packet));

    cout << "Binary packet written to Packet 1." << endl;
    cout << endl;

    pool.deallocate(packet2);

    cout << "Packet 2 released." << endl;
    cout << endl;

    cout << "Available blocks: " << pool.availableBlocks() << endl;
    cout << "Allocated blocks: " << pool.allocatedBlocks() << endl;
    cout << endl;

    void* packet4 = pool.allocate();

    cout << "Packet 4 allocated: " << packet4 << endl;

    if (packet4 == packet2)
    {
        cout << "Packet 4 reused the previously released block." << endl;
    }

    cout << endl;

    cout << "Attempting to exhaust pool..." << endl;

    void* packet5 = pool.allocate();
    void* packet6 = pool.allocate();
    void* packet7 = pool.allocate();
    void* packet8 = pool.allocate();
    void* packet9 = pool.allocate();

    if (packet9 == nullptr)
    {
        cout << "No blocks available." << endl;
        cout << "allocate() returned nullptr." << endl;
    }

    cout << endl;

    cout << "Attempting double deallocation..." << endl;

    pool.deallocate(packet2);

    if (pool.deallocate(packet2))
    {
        cout << "Double deallocation accepted." << endl;
	}
}
