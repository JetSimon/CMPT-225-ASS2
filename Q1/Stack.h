#pragma once

/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Jet Simon and Shadi Zoldjalali 
 * Date: 2/11/2022
 */

class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Description:  head = ptr to the first StackNode (NULL if empty)
        //               tail = ptr to the last StackNode (NULL if empty)
        // Class Invariant:  Follows Assignment 2 requirements, namely that the implementation 
        //                   is a singly-linked list, with insert/remove 
        //                   operations at the list's tail.
        StackNode * head;
        StackNode * tail;

        int elementCount;

    public:

        // Description:  Constructor
        // Postcondition:  Stack is empty
        Stack();


        // Description: Destructor
        // Postcondition: All StackNode objects in Stack deleted
        ~Stack();


        // Description:  Insert element x to the top of the stack.
        // Postcondition:  StackNode with data x is appeneded to the tail of the stack. elementCount++
        void push(int x);


        // Description:  Remove and return element at the top of the stack.
        // Precondition: Stack has elements to pop, else returns -1
        // Postcondition: Returns data from tail of stack, removes StackNode from stack
        int pop();


        // Description:  Return the topmost element of the stack.
        // Precondition: Stack has at least 1 element 
        // Postcondition: Return element from top of stack (ie the tail)
        int peek() const;


        // Description: Check if stack is empty
        // Postcondition: Returns true if elementCount == 0
        bool isEmpty() const;

        // Description: A debugging tool. Prints elements of a stack starting from the head
        // Postcondition: Stack printed to console starting from head, seperated by spaces.
        //void printStack(); //COMMENTED OUT FOR FINAL SUBMISSION TO AVOID BUGS
};


