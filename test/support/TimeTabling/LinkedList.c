#include "LinkedList.h"
#include <string.h>
#include <malloc.h>

LinkedList *linkListNew(void *data){
  LinkedList *link = malloc( sizeof(LinkedList) );
  link->data = data;
  link->next = NULL;

  return link;
}

void clearLinkList(LinkedList *link){
  if(link!=NULL){  
    if(link->next!=NULL){
      clearLinkList(link->next);  
    }
    free(link);
  }
}

void addDataToTail(LinkedList *link, void *data){
  LinkedList *current = link;
  
  while (current->next != NULL){
    current = current->next;
  }
  current->next = malloc(sizeof(LinkedList));
  current->next->data = data;
  current->next->next = NULL;
}