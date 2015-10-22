#ifndef RedBlackTreeAdd_H
#define RedBlackTreeAdd_H
#include"Node.h"

void addRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object));
void _addRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object));

#endif // RedBlackTreeAdd_H
