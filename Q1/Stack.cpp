/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Jet Simon and Shadi Zoldjalali
 * Date: 2/11/2022
 */
 
#include <cstddef>  // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

// Description:  Constructor
// Postcondition:  Stack is empty
Stack::Stack()
{
    head = NULL;
    tail = NULL;
    elementCount = 0;
}

// Description: Destructor
// Postcondition: All StackNode objects in Stack deleted
Stack::~Stack()
{
    //If stack is already empty then we don't need to destroy anything
    if(isEmpty()) return;

    //Traverse through all nodes and destroy them
    StackNode* current = head;

    while(current->next != NULL)
    {
        StackNode* next = current->next;
        delete current;
        current = next;
    }

    //Destroy the final node
    delete current;
}

// Description:  Insert element x to the top of the stack.
// Postcondition:  StackNode with data x is appeneded to the tail of the stack. elementCount++
void Stack::push(int x)
{
    StackNode *node = new StackNode();
    node->data = x;

    if(elementCount == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }

    elementCount++;
}

// Description:  Remove and return element at the top of the stack.
// Precondition: Stack has elements to pop, else returns -1
// Postcondition: Returns data from tail of stack, removes StackNode from stack
int Stack::pop()
{
    if(elementCount == 0)
    {
        cout << "WARNING STACK IS EMPTY CANNOT POP. RETURNING -1";
        return -1;
    }

    StackNode *current = head;
    int toReturn = tail->data;

    if(head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
        elementCount = 0;
        return toReturn;
    }

    while(current->next != tail)
    {
        current = current->next;
    }

    delete tail;
    tail = current;
    current->next = NULL;
    elementCount--;

    return toReturn;
}

// Description:  Return the topmost element of the stack.
// Precondition: Stack has at least 1 element 
// Postcondition: Return element from top of stack (ie the tail)
int Stack::peek() const
{
    return tail->data;
}

// Description: Check if stack is empty
// Postcondition: Returns true if elementCount == 0
bool Stack::isEmpty() const
{
    return elementCount == 0;
}

// Description: A debugging tool. Prints elements of a stack starting from the head
// Postcondition: Stack printed to console starting from head, seperated by spaces.
/*void Stack::printStack()
{
    cout << "STARTING FROM HEAD:\n";
    StackNode* current = head;

    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}*/

