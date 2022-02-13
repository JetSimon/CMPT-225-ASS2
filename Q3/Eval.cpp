/* 
 * Eval.cpp
 *
 * Description: Solves an Infix operation by utilizing two stacks;
 *              number stack and operator stack
 *
 * Invariant: input is well-formed
 *            negative numbers cannot be inputted (use arithmetic ex: to use -1 do (2-3))
 *              
 * Author: Shadi Zoldjalali and Jet Simon
 * Date: 2/13/2022
 */

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
                // perform operation
                res = calc(numstack, opstack);
                // push the result to the number stack
                numstack.push(res);
            }
        }
        // else if T is +, - or EOF:
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            // if the operator stack is nonempty and the top is one of +, -, *, /:
            if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
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
                // push T to the operator stack; get the next token
                opstack.push(t);
                t = S.getnext();
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
    }

    // calculate everything that's left in the stacks
    while (!opstack.isEmpty())
    {
        res = calc(numstack, opstack);
        numstack.push(res);
    }

    // cout the answer
    cout << numstack.peek().val << endl;

    return 0;
}