#include <stdlib.h>
#include "disjointSet.h"

/*
    Disjoint set data structure.
*/

struct disjointSetCDT {
    int arr[101];
};

disjointSetADT getNewDisjointSet() {
    disjointSetADT ds = (disjointSetADT)malloc(sizeof(*ds));
    for (int i = 100; i > 0; i--) {
        ds->arr[i] = -1;
    };
    return ds;
};

void setUnion(disjointSetADT ds, int i, int j) {
    int n = find(i, ds);
    int m = find(j, ds);
    if (n != m) {
        if (-(ds->arr[n]) < -(ds->arr[m])) {
            ds->arr[n] = m;
        }
        else {
            if (ds->arr[n] == ds->arr[m]) {
                (ds->arr[n])--;
            };
            ds->arr[m] = n;
        };
    };
};

int find(int i, disjointSetADT ds) {
    if (ds->arr[i] <= 0) {
        return i;
    };
    return find(ds->arr[i], ds);
};
