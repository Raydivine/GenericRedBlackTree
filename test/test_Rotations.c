#include "unity.h"
#include "Rotations.h"
#include "InitNode.h"

Node node1,node2,node3,node4 ,node5, node6, node7, node8, node9, node10, node15; //Share to all test
int one=1, two=2, three=3, four=4, five=5, six=6, seven=7, eight=8, nine=9, ten=10, fifteen = 15;

void setUp(void){
  
	resetNode(&node1, &one);
	resetNode(&node2, &two);
	resetNode(&node3, &three);
	resetNode(&node4, &four);
	resetNode(&node5, &five);
	resetNode(&node6, &six);
	resetNode(&node7, &seven);
	resetNode(&node8, &eight);
	resetNode(&node9, &nine);
	resetNode(&node10, &ten);
	resetNode(&node10, &fifteen);
}

void tearDown(void)	{}

/*
 * Root->  10
 *		    /                 5 <-Root
 *       5       --->     /  \
 *      /                1   10 
 *     1
 */
void test_rightRotate_3_elements(void)	{
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node5, &node1, NULL, 'b');
	setNode(&node10, &node5, NULL, 'b');
	Node *root = &node10;
	
	rightRotate(&root);	
	TEST_ASSERT_EQUAL_PTR(node1.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left  , &node1);
	TEST_ASSERT_EQUAL_PTR(node5.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root ->  3                    2  <- Root
 *         /  \                /  \
 *        2   4    --->   		1    3
 *       /                          \
 *      1                           4
 */
void test_rightRotate_4_elements(void){

	setNode(&node1, NULL, NULL, 'b');
	setNode(&node4, NULL, NULL, 'b');
	setNode(&node2, &node1, NULL, 'b');
	setNode(&node3, &node2, &node4, 'b');
  Node *root = &node3;

  rightRotate(&root);

  TEST_ASSERT_EQUAL_PTR(node1.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node4.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node4.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.right, &node4);
  TEST_ASSERT_EQUAL_PTR(node2.left , &node1);
  TEST_ASSERT_EQUAL_PTR(node2.right, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
}

/*
 * Root ->   4                 2  <- Root
 *         /  \           	 /  \
 *        2   5 	 --->     1   4
 *       / \               		/  	\
 *      1   3            		 3   	5
 */
void test_rightRotate_5_elements(void){
	setNode(&node1, NULL, NULL, 'b');
	setNode(&node3, NULL, NULL, 'b');
	setNode(&node5, NULL, NULL, 'b');
	setNode(&node2, &node1, &node3, 'b');
	setNode(&node4, &node2, &node5, 'b');
  Node *root = &node4;

  rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node1.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node3.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node5.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node4.left , &node3);
	TEST_ASSERT_EQUAL_PTR(node4.right, &node5);
  TEST_ASSERT_EQUAL_PTR(node2.left , &node1);
	TEST_ASSERT_EQUAL_PTR(node2.right, &node4); 
	TEST_ASSERT_EQUAL_PTR(root, &node2);
}

/*
 * Root ->  1								 2  <- Root
 *           \       			 /  \        
 *            2    ---> 	1    3   
 *            \           
 *             3
 */
void test_leftRotate_3_elements(void){
	setNode(&node3, NULL, NULL, 'b');
	setNode(&node2, NULL, &node3, 'b');
	setNode(&node1, NULL, &node2, 'b');
  Node *root = &node1;

  leftRotate(&root);
  TEST_ASSERT_EQUAL_PTR(node1.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node1.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node3.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node3.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node2.left , &node1);
  TEST_ASSERT_EQUAL_PTR(node2.right, &node3);
  TEST_ASSERT_EQUAL_PTR(root, &node2);
}

/* 
 * Root ->   3								 5  <- Root
 *          / \            	 /  \   
 *         2   5    --->    3    8 
 *              \          / 
 *               8				2
 */
void test_leftRotate_4_elements(void){
	setNode(&node2, NULL, NULL, 'b');
	setNode(&node8, NULL, NULL, 'b');
	setNode(&node5, NULL, &node8, 'b');
	setNode(&node3, &node2, &node5, 'b');
  Node *root = &node3;

  leftRotate(&root);
  TEST_ASSERT_EQUAL_PTR(node2.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node2.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node8.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.left , &node2);
  TEST_ASSERT_EQUAL_PTR(node3.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node5.left , &node3);
  TEST_ASSERT_EQUAL_PTR(node5.right, &node8);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/* 
 * Root ->   3								 5  <- Root
 *          / \            	 /  \   
 *         2   5    --->    3    8 
 *            / \          / \
 *           4  8				  2		4
 */
void test_leftRotate_6_elements(void){
	setNode(&node2, NULL, NULL, 'b');
	setNode(&node8, NULL, NULL, 'b');
  setNode(&node4, NULL, NULL, 'b');
	setNode(&node5, &node4, &node8, 'b');
	setNode(&node3, &node2, &node5, 'b');
  Node *root = &node3;

  leftRotate(&root);
  TEST_ASSERT_EQUAL_PTR(node2.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node2.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node4.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node4.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node8.left , NULL);
  TEST_ASSERT_EQUAL_PTR(node8.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node3.left , &node2);
  TEST_ASSERT_EQUAL_PTR(node3.right, &node4);
  TEST_ASSERT_EQUAL_PTR(node5.left , &node3);
  TEST_ASSERT_EQUAL_PTR(node5.right, &node8);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
}

/*
 * Root->  10        Root->   7
 *        /                 /  \ 
 *       5       -->       5    10
 *        \                 
 *        7              
 */
void test_leftRightRotate_3_elements(void)	{
	setNode(&node7, NULL	, NULL	,	'b');
	setNode(&node5, NULL	, &node7, 'b');
	setNode(&node10,&node5, NULL	, 'b');
	Node *root = &node10;
	
  leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node5.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node7.left  , &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}

/*
 * Root->  10        Root->   7
 *        /                 /  \ 
 *       5       -->       5    10
 *     /   \    					/             
 *    3     7            3  
 */
void test_leftRightRotate_4_elements(void)	{
	setNode(&node7,  NULL,   NULL,   'b');
	setNode(&node3,  NULL,   NULL,   'b');
	setNode(&node5,  &node3, &node7, 'b');
	setNode(&node10, &node5, NULL, 	 'b');
	Node *root = &node10;
	
  leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node3.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node3.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left  , &node3);
	TEST_ASSERT_EQUAL_PTR(node5.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node7.left  , &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}

/*
 * Root->  10       	 Root->   7
 *        /  \             	  /  \ 
 *       5   15    -->       5    10
 *     /   \    						/    /  \         
 *    3     7          	   3    8		15
 *					 \
 *				 		8
 */
void test_leftRightRotate_6_elements(void)	{
	setNode(&node8 ,  NULL,   NULL,   'b');
	setNode(&node3 ,  NULL,   NULL,   'b');
	setNode(&node15,  NULL,   NULL,   'b');
	setNode(&node7 ,  NULL,		&node8, 'b');
	setNode(&node5 ,  &node3, &node7, 'b');
	setNode(&node10,  &node5, &node15,'b');
	Node *root = &node10;
	
  leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node3.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node3.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node8.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node8.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left  , &node3);
	TEST_ASSERT_EQUAL_PTR(node5.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left , &node8);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
  TEST_ASSERT_EQUAL_PTR(node7.left  , &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}

/*
 * Root->  10       	 Root->   7
 *        /  \             	  /  \ 
 *       5   15    -->       5    10
 *     /   \    						/ \  		\         
 *    3     7          	   3   6  		15
 *				 /
 *				6 		
 */
void test_leftRightRotate_6_and_grandLeftChild_elements(void){
	setNode(&node6 ,  NULL,   NULL,   'b');
	setNode(&node3 ,  NULL,   NULL,   'b');
	setNode(&node15,  NULL,   NULL,   'b');
	setNode(&node7 ,  &node6,	NULL, 	'b');
	setNode(&node5 ,  &node3, &node7, 'b');
	setNode(&node10,  &node5, &node15,'b');
	Node *root = &node10;
	
  leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node3.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node3.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node6.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node6.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right, NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left  , &node3);
	TEST_ASSERT_EQUAL_PTR(node5.right , &node6);
	TEST_ASSERT_EQUAL_PTR(node10.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, &node15);
  TEST_ASSERT_EQUAL_PTR(node7.left  , &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}

/*
 * Root->   5                Root->    7
 *           \                       /  \ 
 *            10     -->            5    10
 *           /   
 *          7      
 */
void test_rightLeftRotate_3_elements(void)	{
	setNode(&node7	, NULL	, NULL	 , 'b');
 	setNode(&node10	, &node7, NULL	 , 'b');
	setNode(&node5	, NULL	, &node10, 'b');

	Node *root = &node5;
	
  rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(node5.left  , NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left , NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right, NULL);
  TEST_ASSERT_EQUAL_PTR(node7.left  , &node5);
	TEST_ASSERT_EQUAL_PTR(node7.right , &node10);
	TEST_ASSERT_EQUAL_PTR(root, &node7);  
}