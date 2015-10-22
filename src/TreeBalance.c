#include "TreeBalance.h"
#include "Rotations.h"
#include "Node.h"

void TreeBalancingAndColorFlopping( Node **rootPtr){
  Node *root = *rootPtr;

  if( root->left && !(root->right) ){
     if( root->left->left && !(root->left->right) ){
        rightRotate(&(*rootPtr));
        (*rootPtr)->right->color = 'r';
     }else if( root->left->right && !(root->left->left) ){
        leftRightRotate(&(*rootPtr));
        (*rootPtr)->right->color = 'r';
      }      
  }
  else if(root->right  && !(root->left)  ){
    if( root->right->right  && !(root->right->left) ){
      leftRotate(&(*rootPtr));
      (*rootPtr)->left->color = 'r';
    }else if( root->right->left && !(root->right->right) ){
      rightLeftRotate(&(*rootPtr));
      (*rootPtr)->left->color = 'r';
     }       
  }
}

void TreeBalancing( Node **rootPtr){
  Node *root = *rootPtr;

  if( root->left && !(root->right) ){
     if( root->left->left && !(root->left->right) )
        rightRotate(&(*rootPtr));
     else if( root->left->right && !(root->left->left) )
        leftRightRotate(&(*rootPtr));    
  }
  else if(root->right  && !(root->left)  ){
    if( root->right->right  && !(root->right->left) )
      leftRotate(&(*rootPtr));
    else if( root->right->left && !(root->right->right) )
      rightLeftRotate(&(*rootPtr));   
  }
}
