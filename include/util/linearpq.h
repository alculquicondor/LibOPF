#ifndef _LINEARPQ_H_
#define _LINEARPQ_H_

#include "common.h"

typedef struct _linearpq {
    int *pixel;
    float *cost;
    int s, n;
} LinearPQ;

LinearPQ *CreateLinearPQ(int n, float *cost);
void DestroyLinearPQ(LinearPQ **pq);
char IsEmptyLinearPQ(LinearPQ *pq);
char RemoveLinearPQ(LinearPQ *pq, int *pixel);


#endif
