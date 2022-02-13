/*
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Shadi Zoldjalali and Jet Simon
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
    // cout << "capacity=" << capacity << "element count=" << elementCount << endl;
    if (frontindex + backindex >= capacity)
    {
        capacity *= 2;
        // cout << "\n CAP DOUBLED \n";
        frontindex = 0;
    }

    // create new array
    int *newelements = new int[capacity];
    int count = frontindex;

    // copy over elements
    for (int i = 0; i < elementCount - 1; i++)
    {
        // cout << "**count = " << count << "elementscount = " << elements[count] << "**\n\n";
        newelements[i] = elements[count];
        // cout << "\nnewelements[ " << i << " ] = " << elements[count] << "**\n";
        count++;
    }

    // delete elements and point to new elements
    delete[] elements;
    elements = newelements;

    // add new element to the back of Queue
    elements[backindex] = x;
    // cout << "BACK - elements " << backindex << " = " << elements[backindex] << "**\n\n";
    // cout << "front - elements " << frontindex << " = " << elements[frontindex] << "**\n\n";

    backindex = (backindex + 1) % capacity;

    // cout << "\n**enqueue**\n";
    // cout << "\n**backindex = " << backindex << endl;
    // cout << "\n**frontindex = " << frontindex << endl;
    // cout << "\n**elementcount = " << elementCount << endl;

    // // copy over elements
    // for (int i = 0; i < elementCount; i++)
    // {
    //     cout << "\nelements[ " << i << " ] = " << elements[i] << "**\n";
    // }
}

// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
void Queue::dequeue()
{
    elementCount--;
    // frontindex++;

    // cout << "CAPACITY: " << capacity <<  " elementcount = " << elementCount << endl;
    //  see if we capacity utilization is inefficicent
    if (capacity / 4 > elementCount)
    {
        if (capacity / 2 < INITIAL_CAPACITY)
            capacity = INITIAL_CAPACITY;
        else
            capacity /= 2;
        //cout << "CAP HALVED" << endl;
        // frontindex = 0;
        // need to resize the array, make a new array and copy values
        // create new array
        int *newelements = new int[capacity];
        int count = frontindex + 1;

        // copy over elements
        for (int i = 0; i < elementCount; i++)
        {
            // cout << "**count = " << count << "elementscount = " << elements[count] << "**\n\n";
            newelements[i] = elements[count];
            // cout << "\nnewelements[ " << i << " ] = " << elements[count] << "**\n";
            count++;
        }

        // delete elements and point to new elements
        delete[] elements;
        elements = newelements;

        // for (int i = 0; i < elementCount; i++)
        // {
        //     cout << "\nelements[ " << i << " ] = " << elements[i] << "**\n";
        // }
    }

    frontindex = (frontindex + 1) % capacity;
    backindex--;
    // cout << "\nfront - elements " << frontindex << " = " << elements[frontindex] << "**\n\n";
    // cout << "\nBACK - elements " << backindex << " = " << elements[backindex] << "**\n\n";

    // backindex--;
    //  cout << "\n**dequeue**\n";
    //  cout << "\n**backindex = " << backindex << endl;
    //  cout << "\n**frontindex = " << frontindex << endl;

    // for (int i = frontindex; i < elementCount + frontindex; i++)
    // {
    //     cout << "\nelements[ " << i << " ] = " << elements[i] << "**\n";
    // }
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
