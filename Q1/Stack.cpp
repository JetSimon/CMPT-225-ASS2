/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
 
#include <cstddef>  // For NULL
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    head = NULL;
    tail = NULL;
    elementCount = 0;
}

Stack::~Stack()
{
    if(isEmpty()) return;

    StackNode* current = head;

    while(current->next != NULL)
    {
        StackNode* next = current->next;
        delete current;
        current = next;
    }

    delete current;
}

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

int Stack::peek() const
{
    return tail->data;
}

bool Stack::isEmpty() const
{
    return elementCount == 0;
}

void Stack::printStack()
{
    cout << "STARTING FROM HEAD:\n";
    StackNode* current = head;

    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

