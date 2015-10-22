#include "CaseSelect.h"
#include "CaseHandle.h"
#include "TreeChecking.h"
#include "Node.h"
#include <stdio.h>

void caseSelect( Node **rootPtr){
  Node *root = *rootPtr;

  if(root){  
    if( checkForEnterCase1(root) ){
     // printf("enter case1\n");
      NephewIsRedSiblingIsBlack(&(*rootPtr));  
    }
    else if( checkForEnterCase2(root) ){
   //   printf("enter case2\n");
      NephewAndSiblingIsBlack(&(*rootPtr));     
    }
    else if( checkForEnterCase3(root) ){
    //  printf("enter case3\n");
      SiblingIsRed(&(*rootPtr));       
    }
  }
}

void caseSelectForSucessor( Node **rootPtr){

  Node *root = (*rootPtr)->right;
  if(root == NULL )
    return;
  
  if(root ){
    if(root->color == 'b'){
      if((root->right && root->right->color =='r')||(root->left  && root->left->color == 'r')){
        NephewIsRedSiblingIsBlack(&(*rootPtr)); 
        //printf("enter Sucessor case1\n");
      }
      else if(( root->right == NULL ||  root->right->color == 'b') && (root->left == NULL || root->left->color == 'b')){
        NephewAndSiblingIsBlack(&(*rootPtr));   
        //printf("enter Sucessor case2\n");
      }
    }
   else if(root->color == 'r' && (root->left||root->right)){
      SiblingIsRed(&(*rootPtr));   
       //printf("enter Sucessor case3\n");
   }
  }
}
