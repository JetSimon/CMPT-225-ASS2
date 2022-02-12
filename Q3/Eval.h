// Eval.h
// provides a function that is used in Eval.cpp
// avoides writing code multiple times

#include "Scanner.h"
#include "Stack.h"
using namespace std;

Token calc(Stack<Token> &nums, Stack<Token> &ops)
{
    int x = nums.pop().val;
    int y = nums.pop().val;
    Token sign = ops.pop();
    Token res;
    res.tt = integer;
    // perform the operation
    if (sign.tt == pltok)
    {
        res.val = y + x;
    }
    else if (sign.tt == mitok)
    {
        res.val = y - x;
    }
    else if (sign.tt == asttok)
    {
        res.val = y * x;
    }
    else if (sign.tt == slashtok)
    {
        res.val = y / x;
    }
    res.text = to_string(res.val);
    return res;
}