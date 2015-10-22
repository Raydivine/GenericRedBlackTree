#include "RedBlackTreeDel.h"
#include "TreeChecking.h"
#include "CaseSelect.h"
#include "Node.h"
#include "ErrorCode.h"
#include <stdio.h>

Node *delRedBlackTree( Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object)){
  Node *node =_delRedBlackTree(rootPtr, newNode, compareNode);
  Node *root = *rootPtr;
  
  if(root != NULL)
    root->color = 'b';

  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *newNode, int (*compareNode)(void *data, void *object)){

  Node *root = *rootPtr, *node , *successorNode;
  if(root == NULL)
    Throw(ERR_NODE_UNAVAIBLE);

  if(compareNode(root->data, newNode->data) == 0){
    if(root->left || root->right){      //Checking is the removeNode has childNode
      successorNode = removeNextLargerSuccessor(&(*rootPtr)->right);
      successorNode->left  = (*rootPtr)->left;
      successorNode->right = (*rootPtr)->right;
      *rootPtr = successorNode;
    }
    else *rootPtr = NULL;
    return root;
  }
  else if(compareNode(root->data, newNode->data) == 1)
    node = _delRedBlackTree( &root->right, newNode, compareNode);
  else if(compareNode(root->data, newNode->data) == -1)
    node = _delRedBlackTree( &root->left, newNode, compareNode);
  
  caseSelect(&(*rootPtr));
  return node;
}

Node *removeNextLargerSuccessor(Node **parentPtr){
  Node *parent = *parentPtr, *removeNode;

  if(parent->left == NULL && parent->right == NULL){
    removeNode = *parentPtr;
    *parentPtr = NULL;
  }
  else if(parent->left){
    removeNode = removeNextLargerSuccessor(&(*parentPtr)->left);
    if(isDoubleBlack((*parentPtr)->left, removeNode)) 
      caseSelectForSucessor(&(*parentPtr)); 
  }
  else{
    removeNode = parent;
    *parentPtr = parent->right;
    (*parentPtr)->color = parent->color;
  }
  return removeNode;
}


