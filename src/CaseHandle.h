#ifndef CaseHandle_H
#define CaseHandle_H
#include "Node.h"

void ForceChildNodeToBlack(Node **rootPtr);
void ForceChildNodeToRed( Node **rootPtr);
void NephewIsRedSiblingIsBlack(Node **rootPtr);
void NephewAndSiblingIsBlack(Node **rootPtr);
void SiblingIsRed(Node **rootPtr);

#endif // CaseHandle_H
