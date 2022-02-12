#include "Eval.h" // for operation function

#include <iostream>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open ("samples/expn.1");
    Scanner S(myfile);
    Token t, res;
    Stack<Token> numstack, opstack; // 2x Stacks of type Token


    t = S.getnext();

    // while T is not EOF or the operator stack is non empty
    while (t.tt != eof || !opstack.isEmpty())
    {
        cout << "tt: " << t.tt << endl;
        cout << "NUM STACK: " << numstack.getStackString() << endl;
        cout << "OP STACK: " << opstack.getStackString() << endl;
        cout << "t is " << t.text << endl;
        // if T is a number:
        if (t.tt == integer)
        {
            cout << "integer" << endl;
            // push T to the number stack; get the next token
            numstack.push(t);
            cout << "pushed " << t.text << endl;
            t = S.getnext();
            cout << "ran getnext" << endl;
            cout << "t  IN INT is " << t.text << endl;
            if (t.tt == eof)
                cout << "EOF\n";
            else
                cout << t.text << endl;
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
                // perform operation
                res = calc(numstack, opstack);
                // push the result to the number stack
                numstack.push(res);
                // pop left parantheses
                opstack.pop();
            }
        }
        // else if T is +, - or EOF:
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            // if the operator stack is nonempty and the top is one of +, -, *, /:
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == slashtok))
            {
                cout << "iter 1 " << endl;
                // pop the top two numbers and the top operator
                // perform operation
                res = calc(numstack, opstack);
                // cout << "res is " << res.text << endl;
                // push the result to the number stack
                numstack.push(res);
            }
            // else:
            else
            {
                cout << "iter 2 " << endl;

                // push T to the operator stack; get the next token
                opstack.push(t);
                t = S.getnext();

                if (t.tt == eof)
                    cout << "EOF\n";
            }
        }
        // else if T is * or /:
        else if (t.tt == asttok || t.tt == slashtok)
        {
            // if the operator stack is nonempty and the top is one of *, /:
            if (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                // pop the top two numbers and the top operator
                // perform operation
                res = calc(numstack, opstack);
                // push the result to the number stack
                numstack.push(res);
            }
            // else:
            else
            {
                // push T to the operator stack; get the next token
                opstack.push(t);
                t = S.getnext();
            }
        }
        // if (!numstack.isEmpty())
        //     cout << "numstack is " << numstack.peek().text << endl;
        // if (!opstack.isEmpty())
        //     cout << "opstack is " << opstack.peek().text << endl;
    }
    cout << "out" << endl;

    while (!opstack.isEmpty())
    {
        res = calc(numstack, opstack);
        numstack.push(res);
    }

    cout << numstack.peek().val << endl;

    // // Pretty printer coding demo.  Please remove before coding
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

    // cout << endl;
    // // End pretty printer coding demo.
    myfile.close();
    return 0;
}