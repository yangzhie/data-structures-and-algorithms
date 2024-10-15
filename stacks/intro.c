#include <stdio.h>

int main()
{
    return 0;
}

/*
 * Ordered list
 * A container which follows rules for insertion and deletion for data
 * Insertion & deletion is possible only from one end
 * 
 * LIFO: Last In, First Out
 * FILO: First In, Last Out
 * 
 * Insertion: push(arg)
 * Deletion: pop()
 * Inspect: peek() / top() - retrives top element of stack w/o removing it
 * Empty: isEmpty() - boolean, returns true if stack is empty
 * Full: isFull() - boolean, returns true if stack is full
 * Many more operations
 * 
 * All data should be of same type
 * 
 * Static implementation: using arrays
 * Dymanic implementation: using linked lists
 * 
 * In an empty stack:
 * - top() = -1
 * - Indexed 0 to 4 (for size = 5)
 * - If pop() is called, underflow condition
 * - If push(2), top becomes 0, etc etc
 * - If stack is full and additional push(), overflow condition
 * 
 * Applications:
 * - Reverse a string
 * - Undo mechanism (i.e. for a text editor)
 * - Recursion / function calls
 * - Verify the balance of paranthesis - for each open { there is a closed }
 * - Infix/Postfix/Prefix conversion
 * - Evaluation of Postfix expression
 */