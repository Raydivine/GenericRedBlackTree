#include "CompareObjects.h"
#include "ExamStruct.h"

int compareLecturesID(void *a, void *b){
  
  Lecture *x = (Lecture*)a; 
  Lecture *y = (Lecture*)b; 
  
  if(y->ID > x->ID)
    return 1;
  else if(y->ID < x->ID)
    return -1;
  else
    return 0;
}