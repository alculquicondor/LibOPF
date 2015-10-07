#include "linearpq.h"

LinearPQ *CreateLinearPQ(int n, float *cost) {
    LinearPQ *pq;
    int i;

    if (cost == NULL) {
        fprintf(stdout,"Cannot create priority queue without cost map in CreateLinearPQ");
        return NULL;
    }

    pq = (LinearPQ *) malloc(sizeof(LinearPQ));
    if (pq != NULL) {
        pq->pixel = (int *) malloc(sizeof(int) * n);
        pq->cost = cost;
        pq->n = n;
        pq->s = 0;
        if (pq->pixel == NULL)
            Error(MSG1,"CreateLinearPQ");
        for (i = 0; i < n; i++)
            pq->pixel[i] = i;
    } else {
        Error(MSG1,"CreateLinearPQ");
    }

    return pq;
}

void DestroyLinearPQ(LinearPQ **pq) {
    LinearPQ *aux = *pq;
    if (aux != NULL) {
        if (aux->pixel != NULL)
            free(aux->pixel);
        free(aux);
        *pq = NULL;
    }
}

char IsEmptyLinearPQ(LinearPQ *pq) {
    return pq->s == pq->n;
}

char RemoveLinearPQ(LinearPQ *pq, int *pixel) {
    if (!IsEmptyLinearPQ(pq)) {
        int i = pq->s, j;
        for (j = i + 1; j < pq->n; j++)
            if (pq->cost[pq->pixel[i]] > pq->cost[pq->pixel[j]])
                i = j;
        if (i != pq->s)
            Change(&pq->pixel[pq->s], &pq->pixel[i]);
        *pixel = pq->pixel[pq->s++];
        return 1;
    } else {
        return 0;
    }
}
