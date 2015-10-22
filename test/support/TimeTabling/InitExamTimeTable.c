#include "InitExamTimeTable.h"
#include "ExamStruct.h"
#include <stdio.h>

void setLecture(Lecture *lecture, int ID, char *name){
  lecture->ID = ID;
  lecture->name = name;
}