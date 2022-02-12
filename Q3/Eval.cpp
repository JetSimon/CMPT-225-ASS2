
#include "Scanner.h"
#include "Stack.h" // GENERIC STACK

#include <iostream>
using namespace std;

int main()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack; // 2x Stacks of type Token

    t = S.getnext();

    // while T is not EOF or the operator stack is non empty
    while (t.tt != eof || opstack.isEmpty() == false)
    {
        // if T is a number:
        if (t.tt == integer)
        {
            // push T to the number stack; get the next token
            numstack.push(t);
            t = S.getnext();
        }
        // else if T is a left parenthesis:
        else if (t.tt == lptok)
        {
            // push T to the operator stack; get the next token
            opstack.push(t);
            t = S.getnext();
        }
        // else if T is a right parenthesis:
        else if (t.tt == rptok)
        {
            // if the top of the operator stack is a left parenthesis:
            if (opstack.peek().tt == lptok)
            {
                // pop it from the operator stack; get the next token:
                opstack.pop();
                t = S.getnext();
            }
            // else:
            else
            {
                // pop the top two numbers and the top operator
                int x = numstack.pop().val;
                int y = numstack.pop().val;
                Token c = opstack.pop();
                // perform the operation
                // Token res = y + x
                // push the result to the number stack
                // numstack.push(res);
            }
        }
        // else if T is +, - or EOF:
        //     if the operator stack is nonempty and the top is one
        //                                         of +, -, *, /:
        //         pop the top two numbers and the top operator
        //         perform the operation
        //         push the result to the number stack
        //     else:
        //         push T to the operator stack; get the next token

        // else if T is * or /:
        //     if the operator stack is nonempty and the top is one of *, /:
        //         pop the top two numbers and the top operator
        //         perform the operation
        //         push the result to the number stack
        //     else:
        //         push T to the operator stack; get the next token
    }

    // Pretty printer coding demo.  Please remove before coding
    // while (t.tt != eof)
    // {
    //     if (t.tt == integer || t.tt == lptok || t.tt == rptok)
    //     {
    //         cout << t;
    //     }
    //     else if (t.tt == pltok || t.tt == mitok ||
    //              t.tt == asttok || t.tt == slashtok)
    //     {
    //         cout << ' ' << t << ' ';
    //     }

    //     t = S.getnext();
    // }

    cout << endl;
    // End pretty printer coding demo.

    return 0;
}
