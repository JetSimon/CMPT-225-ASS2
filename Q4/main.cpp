#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
    Queue Q;
    Queue copy;

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++)
    {
        cout << "enqueue " << i << endl;
        Q.enqueue(i);
    }
    // copy = Q;

    // while (!copy.isEmpty())
    // {
    //     cout << " " << copy.peek();
    //     copy.dequeue();
    // }

    // dequeue 2x elements
    for (int i = 0; i < 2; i++)
    {
        int y = Q.peek();
        cout << "peek " << y << endl;

        Q.dequeue();
    }

    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++)
    {
        cout << "enqueue " << i << endl;
        Q.enqueue(i);
    }

    // dequeue all elements
    while (!Q.isEmpty())
    {
        int y = Q.peek();
        cout << "peek " << y << endl;

        // cout << "y is " << y << endl;
        Q.dequeue();
    }

    return 0;
}
