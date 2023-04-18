#ifndef DISJOINTSET_H_INCLUDED
#define DISJOINTSET_H_INCLUDED

typedef struct disjointSetCDT* disjointSetADT;

disjointSetADT getNewDisjointSet(void);
void setUnion(disjointSetADT, int, int);
int find(int, disjointSetADT);

#endif // DISJOINTSET_H_INCLUDED
