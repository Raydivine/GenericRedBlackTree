#include "unity.h"
#include "Node.h"
#include "InitNode.h"
#include "RedBlackTreeAdd.h"
#include "CustomAssertions.h"
#include "TreeBalance.h"
#include "Rotations.h"
#include "CompareObjects.h"
#include "InitExamTimeTable.h"
#include "ExamStruct.h"
#include "ErrorCode.h"
#include "CException.h"

Node node1, node2, node3, node4, node5, node6, node7, node8, node9, node10, node11, node12, node13, node14, node15;
Lecture lecture1, lecture2, lecture3, lecture4, lecture5, lecture6, lecture7, lecture8, lecture9, lecture10, lecture11, lecture12, lecture13, lecture14, lecture15;

void setUp(void)
{
  setLecture(&lecture1, 1, "Rim");
  setLecture(&lecture2, 2, "Rim");
  setLecture(&lecture3, 3, "Rim");
  setLecture(&lecture4, 4, "Rim");
  setLecture(&lecture5, 5, "Rim");
  setLecture(&lecture6, 6, "Rim");
  setLecture(&lecture7, 7, "Rim");
  setLecture(&lecture8, 8, "Rim");
  setLecture(&lecture9, 9, "Rim");
  setLecture(&lecture10, 10, "Rim");
  setLecture(&lecture11, 11, "Rim");
  setLecture(&lecture12, 12, "Rim");
  setLecture(&lecture13, 13, "Rim");
  setLecture(&lecture14, 14, "Rim");
  setLecture(&lecture15, 15, "Rim");
  
  resetNode(&node1, &lecture1);
  resetNode(&node2, &lecture2);
  resetNode(&node3, &lecture3);
  resetNode(&node3, &lecture3);
  resetNode(&node4, &lecture4);
  resetNode(&node5, &lecture5);
  resetNode(&node6, &lecture6);
  resetNode(&node7, &lecture7);
  resetNode(&node8, &lecture8);
  resetNode(&node9, &lecture9);
  resetNode(&node10, &lecture10);
  resetNode(&node11, &lecture11);
  resetNode(&node12, &lecture12);
  resetNode(&node13, &lecture13);
  resetNode(&node14, &lecture14);
  resetNode(&node15, &lecture15);
}

void tearDown(void)
{
}

/**
 *    Root    add10     Root
 *    /	      --->      /
 *  NULL               1
 */
void test_addRedBlackTree_given_RootNull_and_add_lecture1_to_Node(void){

	Node *root = NULL;
 
  addRedBlackTree(&root,	&node1, compareLecturesID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node1); 
	TEST_ASSERT_EQUAL_PTR(&lecture1, node1.data); 
}

/** 2-node case
 *                 add 10
 * root -> 10(b)  -------> Throw ERR_EQUIVALENT_NODE
 */
void test_addRedBlackTree_add_10_to_use_tree_with_only_root_10_should_throw_ERR_EQUIVALENT_NODE(void)
{
  CEXCEPTION_T err;
  Node *root = &node10;

  Try{
    addRedBlackTree(&root,	&node10, compareLecturesID);
    TEST_FAIL_MESSAGE("Expected ERR_EQUIVALENT_NODE to be thrown. But receive none");
  } Catch(err)
    {
      TEST_ASSERT_EQUAL_PTR(&node10, root);
      TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
    }
}

/**
 *    Root    add5    Root
 *    /       --->   	/
 *  10(b)           10(b)
 *                  /
 *                5(r)
 */
void test_addRedBlackTree_add_5_tree_with_root_10(void){
  setNode(&node10, NULL, NULL, 'b');
	setNode(&node5 , NULL, NULL, 'r');

	Node *root = &node10;
	addRedBlackTree(&root,	&node5, compareLecturesID);
	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node10);
	TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_PTR(&lecture5, node5.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture10, node10.data); 
}

/**
 * 		Root								Root 								 		Root
 *		 |					   			|													|
 *		V				 add9				V 			flip color			  V
 *	 4(b)	   ------->    4[b]			-------->				4(b)
 *  /		\           		/		\										 /	 \
 * 3[r]	7[r]					3[r]	7[r]							3[b]   7[b]
 *														\												\
 *														9[r]										9[r]
 */
void test_addRedBlackTree_add_9_should_flip_color(void){
	setNode(&node3, NULL  , NULL, 'r');
	setNode(&node7, NULL  , NULL, 'r');
	setNode(&node9, NULL  , NULL, 'r');
	setNode(&node4, &node3, &node7, 'b');

	Node *root = &node4;
	addRedBlackTree(&root,	&node9, compareLecturesID);
  TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_EQUAL_PTR(root, &node4);
	TEST_ASSERT_EQUAL_NODE(&node3, &node7, 'b', &node4);
	TEST_ASSERT_EQUAL_NODE(NULL, &node9, 'b', &node7);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node9);
	TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node3);
  TEST_ASSERT_EQUAL_PTR(&lecture4, node4.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture3, node3.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture7, node7.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture9, node9.data); 
}

/**
 *          Root                            Root                                      Root
 *            |                               |                                       |
 *            V             add6              V               flip color             V
 *          10(b)         ------->          10[b]             -------->           10(b)
 *         /	   \                          /     \                               /	   \
 *      2[r]	    13[r]                 2[r]        3[r]                       2[b]       13[b]
 *      /   \	    /   \                /    \      /   \                     /	 \	    /   \
 *  1[b]   8[b]  11[b] 15[b]        1[b]   8[b]  11[b] 15[b]              1[b]   8[r]  11[b] 15[b]
 *          /	\						   							 /	\                                   /	\
 *       3[r]  9[r]                    3[r]  9[r]                             3[b]  9[b]
 *                                         \                                      \
 *                                        6[r]                                    6[r]
 *
 */
void test_addRedBlackTree_add_6_should_flip_color_for_multipleNode_testing(void){
	setNode(&node1 , NULL   , NULL    , 'b');
	setNode(&node11, NULL   , NULL    , 'b');
	setNode(&node15, NULL   , NULL    , 'b');
	setNode(&node3 , NULL   , NULL    , 'r');
	setNode(&node9 , NULL   , NULL    , 'r');
	setNode(&node6 , NULL   , NULL    , 'r');
	setNode(&node8 , &node3 , &node9  , 'b');
	setNode(&node2 , &node1 , &node8  , 'r');
	setNode(&node13, &node11, &node15 , 'r');
	setNode(&node10, &node2 , &node13 , 'b');

	Node *root = &node10;
	addRedBlackTree(&root,	&node6, compareLecturesID);
  TEST_ASSERT_EQUAL_NODE(&node2, &node13, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(&node1, &node8, 'b', &node2);
  TEST_ASSERT_EQUAL_NODE(&node11, &node15, 'b', &node13);
  TEST_ASSERT_EQUAL_NODE(&node3, &node9, 'r', &node8);
  TEST_ASSERT_EQUAL_NODE(NULL, &node6, 'b', &node3);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node11);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node9);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node6);
  TEST_ASSERT_EQUAL_PTR(&lecture6, node6.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture15, node15.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture2, node2.data); 
  TEST_ASSERT_EQUAL_PTR(&lecture9, node9.data); 
}
