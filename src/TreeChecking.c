#include "TreeChecking.h"
#include "Node.h"
#include <stdio.h>

int gotChildNode(Node **rootPtr){
  Node *root = *rootPtr;
  if( root->left || root->right)
    return 1;
  return 0;
}

int noChildNode(Node **rootPtr){
  Node *root = *rootPtr;
  if( !root->left && !root->right)
    return 1;
  return 0;
}

int isDoubleBlack(Node *rootPtr, Node *removedNode){

  if((rootPtr == NULL ||  rootPtr->color == 'd')  &&  (removedNode->color == 'b' ||  removedNode->color == 'r'))
    return 1;
  else  return 0;
}

int bothChildNodeIsBlack(Node *rootPtr){
  if(rootPtr->left->color != 'b' || rootPtr->right->color != 'b')
    return 0;
  return 1;
}

int checkForEnterCase1( Node *root){
    if( root->left && !root->right && root->left->color =='b' ){
      if( (root->left ->right && root->left ->right->color =='r') || (root->left->left && root->left->left->color =='r') )
         return 1;
    }
    else if( root->right && !root->left && root->right->color =='b' ){
      if( (root->right->right && root->right->right->color =='r') || (root->right->left && root->right->left->color =='r') )
         return 1;
    }
    return 0;
}

int checkForEnterCase2( Node *root){
    if(root->left && !root->right){
      if( noChildNode( &(root->left) ) )
        return 1;  
    }
    else if( root->right && !root->left){
      if( noChildNode( &(root->right) ) )
        return 1;
    }
    return 0;
}

int checkForEnterCase3( Node *root){
    if(root->left && root->left->color =='r'){
      if( !root->right || root->right->color =='d')
        return 1;  
    }
    else if( root->right && root->right->color =='r'){
      if( !root->left || root->left->color =='d')
        return 1;
    }
    return 0;
}

