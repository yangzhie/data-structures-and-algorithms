#include <stdio.h>

int main()
{
    return 0;
}

REESEARCH BINARY EXPRESSION TREES FOR POST/PRE FIX

/*
 * Infix to Prefix
 * 1. reverse the expression
 *
 * Example
 * K + L - M * N + (O^P) * W/U/V * T + Q
 * 1. Q + T * V/U/W * ) P^O(+ N*M - L + K
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