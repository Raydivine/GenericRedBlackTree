#ifndef TreeChecking_H
#define TreeChecking_H
#include "Node.h"

int gotChildNode(Node **rootPtr);
int noChildNode(Node **rootPtr);
int isDoubleBlack(Node *rootPtr, Node *removedNode);
int bothChildNodeIsBlack(Node *rootPtr);
int checkForEnterCase1( Node *root);
int checkForEnterCase2( Node *root);
int checkForEnterCase3( Node *root);

#endif // TreeChecking_H
