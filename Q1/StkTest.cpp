
#include "Stack.h"

#include <iostream>

using namespace std;


int main () {
    Stack stk;

    stk.printStack();

    // push 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        stk.push(i);
        cout << "push " << i << endl;
    }

    stk.printStack();

    // pop top two
    for (int i = 0; i < 2; i++) {
        int x = stk.pop();
        int y = stk.peek();
        cout << "pop " << x << ", top " << y << endl;
    }

    stk.printStack();

    // push 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        stk.push(i);
        cout << "push " << i << endl;
    }

    stk.printStack();

    // pop all
    while (!stk.isEmpty()) {
        int x = stk.pop();
        cout << "pop " << x << endl;
    }

    stk.printStack();

    return 0;
}

