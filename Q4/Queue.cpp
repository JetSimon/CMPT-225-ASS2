/*
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */

#include "Queue.h"
#include <iostream>
using namespace std;

// Description:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0)
{
    elements = new int[capacity];
}

// Description: Deconstructor
Queue::~Queue()
{
    delete[] elements;
}

// Description:  Inserts element x at the back (O(n))
void Queue::enqueue(int x)
{
    // add the element
    elementCount++;
    // if capacity is full, double capacity
    if (capacity < elementCount)
        capacity *= 2;

    // create new array
    int *newelements = new int[capacity];

    // copy over elements
    for (int i = 0; i < elementCount - 1; i++)
    {
        newelements[i] = elements[i];
    }

    // delete elements and point to new elements
    delete[] elements;
    elements = newelements;

    // add new element to the back of Queue
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
}

// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
void Queue::dequeue()
{
    elementCount--;

    //see if we capacity utilization is inefficicent
    if (capacity / 4 > elementCount)
    {
        if (capacity / 2 < INITIAL_CAPACITY)
            capacity = INITIAL_CAPACITY;
        else
            capacity /= 2;
    }
    
    frontindex = (frontindex + 1) % capacity;
}

// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
int Queue::peek() const
{
    return elements[frontindex];
}

// Description:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const
{
    return elementCount == 0;
}
