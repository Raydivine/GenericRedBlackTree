#include "CaseHandle.h"
#include "Rotations.h"
#include "TreeBalance.h"
#include "Node.h"

void ForceChildNodeToBlack(Node **rootPtr){
  if((*rootPtr)->left)
    (*rootPtr)->left->color  = 'b';
  if((*rootPtr)->right)
    (*rootPtr)->right->color = 'b';
}

void ForceChildNodeToRed( Node **rootPtr){
  if((*rootPtr)->left)
    (*rootPtr)->left->color  = 'r';
  if((*rootPtr)->right)
    (*rootPtr)->right->color = 'r';
}

//Function for handle case1
void NephewIsRedSiblingIsBlack(Node **rootPtr){
  Node *root = *rootPtr;
  char colour = root->color; //store the original root color

  TreeBalancing( rootPtr);
  ForceChildNodeToBlack(&(*rootPtr));
  (*rootPtr)->color = colour;
}

//Function for handle case2
void NephewAndSiblingIsBlack(Node **rootPtr){
  Node *root = *rootPtr;
  
  if(root->color == 'b')
    root->color = 'd';
  else if(root->color == 'r') 
    root->color = 'b';
 
  if(root->left)
    root->left->color = (root->left->color == 'd')? 'b':'r';
  if(root->right)
    root->right->color = (root->right->color == 'd')? 'b':'r';
  
}

//Function for handle case3
void SiblingIsRed(Node **rootPtr){
  Node *root = *rootPtr;
  char colour = root->color; // store the original root color

  if( root->right ){
    leftRotate(&(*rootPtr));
    (*rootPtr)->left->color = 'r';
    
    if((*rootPtr)->left && ((*rootPtr)->left->right) && ((*rootPtr)->left->right->right) ){
      NephewIsRedSiblingIsBlack(&(*rootPtr)->left); 
     // printf("leftSide, enter case1\n");
    }
    else{
      NephewAndSiblingIsBlack(&(*rootPtr)->left);  
    //  printf("leftSide, enter case2\n");
    }
  }
  else if( root->left ){
    rightRotate(&(*rootPtr));
    (*rootPtr)->right->color = 'r';
    
    if((*rootPtr)->right && ((*rootPtr)->right->left) && ((*rootPtr)->right->left->left)){
      NephewIsRedSiblingIsBlack(&(*rootPtr)->right);  
     // printf("RightSide, enter case1\n");   
    }
    else{
      NephewAndSiblingIsBlack(&(*rootPtr)->right);   
     // printf("RightSide, enter case2\n"); 
    }
  }
  (*rootPtr)->color = colour;
}