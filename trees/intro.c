#include <stdio.h>

int main()
{
}

// Non-linear data structures - data structures that are not sequential
// Has multiple paths to reach the same data
// Heirarchical data structure
// Examples: Trees, Graphs

// Can go from parent to child, but not child to parent
// Direction is always down

// A tree is a collection of nodes linked together to simulate a hierarchy
// Each node has a value and a list of references to other nodes
// The node contains both the data and the reference to the next node

// Topmost node is the root node - one without any parent
// Parent node is the immediate predessor of a node
// Child node is the immediate successor of a node
// Nodes with no children are called leaves (leaf node) (external node)
// Nodes with children are called internal nodes

// Edge is the link between two nodes
// Path is a sequence of consecutive edges from source to destination nodes

// Ancestors of a node is ALL and ANY nodes that lies on the path from the root to the node
// Descendant of a node are ALL and ANY nodes that lies on the path from the node to the leaf

// Sub-tree is a tree that is a part of a larger tree
// It contains a node and all its descendants

// Siblings are nodes that have the same parent
// Degree of a node is the number of children it has
// Degree of a tree is the maximum degree of any node in the tree
// Depth of a node is the number of edges from the root to the node - the depth of root is 0
// Height of a node is the number of edges on the longest path from the node to deepest leaf
// Level of a node is the depth of the node
// Level of a tree is the height of the tree

// If a tree contains n nodes, it has n-1 edges