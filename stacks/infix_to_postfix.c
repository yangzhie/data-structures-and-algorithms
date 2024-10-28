#include <stdio.h>

int main()
{
    return 0;
}

/*
 * General
 * 1. Infix: Operators are written between the operands. Eg: a + b
 * 2. Prefix: Operators are written before the operands. Eg: + a b
 * 3. Postfix: Operators are written after the operands. Eg: a b +
 *
 * These exist to make it easier for the computer to evaluate the expression.
 * No precedence rules are needed in postfix notation.
 *
 * Infix to Postfix
 * 1. print operands as they arrive
 * 2. if stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack
 * 3. if incoming symbol is a left parenthesis, push it on the stack
 * 4. if incoming symbol is a right parenthesis, pop the stack and print the operators until a left parenthesis is found
 * 5. if incoming symbol has higher precedence than the top of the stack, push it on the stack
 * 6. if incoming symbol has lower precedence than the top of the stack, pop and print the top. Then test the incoming operator against the new top of the stack
 * 7. if incoming operator has equal precedence with the top of the stack, use associativity rule
 * 8. at the end of the expression, pop and print all operators of the stack
 * 
 * Associativity is L to R: pop and print the top of the stack and push the incoming operator
 * Associativity is R to L: push in the incoming operator
 *
 * If the precedence of the current scanned operator is higher than the precedence of the operator on top of the stack, or if the stack is empty, or if the stack contains a ‘(‘, then push the current operator onto the stack.
 * Else, pop all operators from the stack that have precedence higher than or equal to that of the current operator. After that push the current operator onto the stack.
 *
 * Example
 * K + L - M * N + (O^P) * W/U/V * T + Q
 * 1. first is K, is an operand, print it
 * 2. next is +, stack is empty, no operator after is, push it on the stack
 * 3. L is an operand so nothing into stack
 * 4. - is an operator, stack is +, + has lower precedence than -, so pop + and print it. Push - on the stack
 * 5. M is an operand, print it
 * 6. * is an operator, stack is -, - has lower precedence than *, so push * on the stack
 * 7. N is an operand, print it
 * 8. + is an operator, stack is *, * has higher precedence than +, so push + on the stack, we compare + with - since we cannot directly push it onto the stack (associativity)
 * 9. ( is an operator, push it onto the stack
 * 10. O is an operand, print it
 * 11. ^ is an operator, there is no other operator preset after opening bracket, push it onto the stack
 * 12. P is an operand, print it
 * 13. ) is an operator, pop and print all operators until ( is found
 * 14. * is an operator, stack is -, - has lower precedence than *, so push * onto the stack
 * 15. W is an operand, print it
 * 16. / is an operator, stack is *, * has higher precedence than /, so push / onto the stack
 * 17. U is an operand, print it
 * 18. / is an operator, stack is /, / has equal precedence with /, so use associativity rule
 * 19. V is an operand, print it
 * 20. * is an operator, stack is /, / has lower precedence than *, so push * onto the stack
 * 21. T is an operand, print it
 * 22. + is an operator, stack is *, * has higher precedence than +, so push + onto the stack
 * 23. Q is an operand, print it
 * 24. end of expression, pop and print all operators of the stack
 *
 * Input Expression               Stack                  Postfix Expression
 *        K                                                K
 *        +                       +                        K
 *        L                       +                        KL
 *        -                       -                        KL+
 *        M                       -                        KL+M
 *        *                       -*                       KL+M
 *        N                       -*                       KL+MN
 *        +                       +                        KL+MN*-
 *        (                       +(                       KL+MN*-
 *        O                       +(                       KL+MN*-O
 *        ^                       +(^                      KL+MN*-O
 *        P                       +(^                      KL+MN*-OP
 *        )                       +                        KL+MN*-OP^
 *        *                       +*                       KL+MN*-OP^
 *        W                       +*                       KL+MN*-OP^W
 *        /                       +/                       KL+MN*-OP^W*
 *        U                       +/                       KL+MN*-OP^W*U
 *        /                       +/                       KL+MN*-OP^W*U/
 *        V                       +/                       KL+MN*-OP^W*U/V
 *        *                       +*                       KL+MN*-OP^W*U/V/
 *        T                       +*                       KL+MN*-OP^W*U/V/T
 *        +                       +                        KL+MN*-OP^W*U/V/T*
 *        Q                       +                        KL+MN*-OP^W*U/V/T*+Q
 *       end                                               KL+MN*-OP^W*U/V/T*+Q+
 */