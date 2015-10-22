#ifndef RedBlackTreeDel_H
#define RedBlackTreeDel_H
#include "Node.h"

Node *delRedBlackTree (Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object));
Node *_delRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object));
Node *removeNextLargerSuccessor(Node **parentPtr);

#endif // RedBlackTreeDel_H
