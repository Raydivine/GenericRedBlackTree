#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList{
  LinkedList *next;
  void *data;
};

LinkedList *linkListNew(void *data); 
void clearLinkList(LinkedList *link); 
void addDataToTail(LinkedList *link, void *data); 

#endif // LinkedList_H
