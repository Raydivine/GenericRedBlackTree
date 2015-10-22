#include "RedBlackTreeAdd.h"
#include "Node.h"
#include "TreeBalance.h"
#include "ErrorCode.h"
#include "CompareObjects.h"
#include <stdio.h>


void addRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object)){
	_addRedBlackTree(rootPtr, newNode, compareNode);
  TreeBalancing( rootPtr);
  (*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object)){
	Node *root = *rootPtr;
	if(root == NULL){
		*rootPtr = newNode;
		return;
	}
  
  if(compareNode(root->data, newNode->data) == 0)
    Throw(ERR_EQUIVALENT_NODE);
	else if(compareNode(root->data, newNode->data) == 1)
		_addRedBlackTree( &root->right,	newNode, compareNode);
  else if(compareNode(root->data, newNode->data) == -1)
		_addRedBlackTree( &root->left ,	newNode, compareNode);

  if(!( (*rootPtr)->right && (*rootPtr)->left) )  // if root->right && root-> left are null
    return;

  else if( root->left->color == root->right->color && ( root->left->left || root->left->right || root->right->right || root->right->left )){
    root->color = 'r';
  	root->left->color = 'b';
  	root->right->color = 'b';
  }
}

