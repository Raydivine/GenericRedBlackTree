#ifndef RedBlackTree_H
#define RedBlackTree_H

int gotChildNode(Node **rootPtr);
int noChildNode(Node **rootPtr);
int isDoubleBlack(Node *rootPtr, Node *removedNode);
int bothChildNodeIsBlack(Node *rootPtr);
int checkForEnterCase1( Node *root);
int checkForEnterCase2( Node *root);
int checkForEnterCase3( Node *root);
void restructureUnBalanceTree( Node **rootPtr);
void restructureUnBalanceTreeWithoutColourFlopping( Node **rootPtr);
void ForceChildNodeToBlack    (Node **rootPtr);
void ForceChildNodeToRed      (Node **rootPtr);
void caseSelect( Node **rootPtr);
void caseSelectForSucessor( Node **rootPtr);
void NephewIsRedSiblingIsBlack(Node **rootPtr);  //case1
void NephewAndSiblingIsBlack  (Node **rootPtr);  //case2
void SiblingIsRed             (Node **rootPtr);  //case3
Node *delRedBlackTree (Node **rootPtr, Node *newNode);
Node *_delRedBlackTree(Node **rootPtr, Node *newNode);
Node *removeNextLargerSuccessor  (Node **parentPtr);

#endif // RedBlackTree_H
