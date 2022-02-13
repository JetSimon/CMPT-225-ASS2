/*
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Shadi Zoldjalali and Jet Simon
 * Date: 2/13/2022
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
    if (frontindex + backindex >= capacity)
    {
        capacity *= 2;
        // reset front index
        frontindex = 0;
    }

    // create new array
    int *newelements = new int[capacity];
    int count = frontindex;

    // copy over elements
    for (int i = 0; i < elementCount - 1; i++)
    {
        newelements[i] = elements[count];
        count++;
    }

    // delete elements and point to new elements
    delete[] elements;
    elements = newelements;

    // add new element to the back of Queue
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
}

// Description:  Removes the frontmost element (O(1))
// --------------O(1) if capacity does not change
// --------------O(n) if capacity decreases
// Precondition:  Queue not empty
void Queue::dequeue()
{
    elementCount--;

    //  see if capacity utilization is inefficicent
    if (capacity / 4 > elementCount)
    {
        if (capacity / 2 < INITIAL_CAPACITY)
            capacity = INITIAL_CAPACITY;
        else
            capacity /= 2;

        // need to resize the array, make a new array and copy values
        // create new array
        int *newelements = new int[capacity];
        int count = frontindex + 1;

        // copy over elements
        for (int i = 0; i < elementCount; i++)
        {
            newelements[i] = elements[count];
            count++;
        }

        // delete elements and point to new elements
        delete[] elements;
        elements = newelements;
    }

    // increase frontindex since element has been removed
    frontindex = (frontindex + 1) % capacity;
    // decrease back index because next available position is closer
    backindex--;
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
