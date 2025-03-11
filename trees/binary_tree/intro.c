#include <stdio.h>

int main()
{
}

// Binary Trees
/*
 A tree in which each node has maximum two children
 Can have 0, 1 or 2 children

 Max no. of nodes at height/level h, n = 2^(h + 1) - 1
 Min height of a tree with n nodes, h = log2(n + 1) - 1

 Max height of a tree with n nodes, h = n - 1
 Min no. of nodes at height/level h. n = h + 1
*/

/*
 Types of Binary Trees

 1. Full/proper/strict Binary Tree
    A binary tree in which each node has 0 or 2 children
 2. Complete Binary Tree
    A binary tree in which all levels are completely filled except possibly the last level
    In the last level, all nodes are as left as possible (L to R - nodes cannot have gaps) - they can also have one leaf node in last level
 3. Perfect Binary Tree
    A binary tree in which all internal nodes have two children and all leaf nodes are at the same level
 4. Degenerate Binary Tree
    A binary tree in which all internal nodes have only 1 child
    Left and right-skewed trees are examples of degenerate trees
*/

/*
 Full Binary Tree

 Leaf nodes = Internal nodes + 1
 Max no. of nodes at height/level h, n = 2^(h + 1) - 1
 Min height of a tree with n nodes, h = log2(n + 1) - 1

 Min no. of nodes at height/level h, n = 2^(h + 1)
 Max height of a tree with n nodes, h = (n - 1)/2
*/

/*
 Complete Binary Tree

 Max no. of nodes at height/level h, n = 2^(h + 1) - 1
 Min height of a tree with n nodes, h = log2(n + 1) - 1

 Min no. of nodes at height/level h, n = 2^h
 Max height of a tree with n nodes, h = log(n)
*/

/*
 Perfect Binary Tree
 Every PBT can be a CBT or FBT, but not vice versa
*/