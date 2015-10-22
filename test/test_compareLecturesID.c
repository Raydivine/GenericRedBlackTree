#include "unity.h"
#include "CompareObjects.h"
#include "InitExamTimeTable.h"
#include "ExamStruct.h"
#include "Node.h"
#include "InitNode.h"

Node node1, node2, node3, node4;
Lecture lecture1, lecture2, lecture3, lecture4;

void setUp(void)
{
  setLecture(&lecture1, 1, "Rim");
  setLecture(&lecture2, 2, "Rim");
  setLecture(&lecture3, 3, "Rim");
  setLecture(&lecture4, 3, "Rim");
  
  resetNode(&node1, &lecture1);
  resetNode(&node2, &lecture2);
  resetNode(&node3, &lecture3);
  resetNode(&node3, &lecture3);
  resetNode(&node4, &lecture4);
}

void tearDown(void)
{
}

void test_compareLecturesID_given_lecture2_compare_lecture3_should_return_1_becuz_lecture3_ID_is_bigger(void){

  int ans = compareLecturesID(node2.data, node3.data);
  TEST_ASSERT_EQUAL(1,ans);
}

void test_compareLecturesID_given_lecture2_compare_lecture1_should_return_minus1_becuz_lecture1_ID_is_smaller(void){

  int ans = compareLecturesID(node2.data, node1.data);
  TEST_ASSERT_EQUAL(-1,ans);
}

void test_compareLecturesID_given_lecture3_compare_lecture41_should_return_0_becuz_their_ID_are_same(void){

  int ans = compareLecturesID(node3.data, node4.data);
  TEST_ASSERT_EQUAL(0,ans);
}

