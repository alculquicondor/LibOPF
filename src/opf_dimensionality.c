#include "OPF.h"
#include <stdio.h>

int main(int argc, char **argv){
    fflush(stdout);
    fprintf(stdout, "\nProgram that calculates the mean, variance and intrinsec dimensionality of an input set\n");
    fprintf(stdout, "\n"); fflush(stdout);

    if(argc != 2){
        fprintf(stderr, "\nusage opf_dimensionality <P1>");
        fprintf(stderr, "\nP1: Dataset in the OPF file format");
        exit(-1);
    }

    Subgraph *sg = ReadSubgraph(argv[1]);
    long double mean = 0;
    long double variance = 0;
    float mini = 1e100;
    float maxi = 0;
    int i;
    int j;
    int n = 0;
    for (i = 0; i < sg->nnodes; i++){
        for (j = i + 1; j < sg->nnodes; j++){
            float x = opf_EuclDist(sg->node[i].feat, sg->node[j].feat, sg->nfeats);
            mini = MIN(mini, x);
            maxi = MAX(maxi, x);
            long double delta = x - mean;
            mean += delta / (++n);
            long double delta2 = x - mean;
            variance += delta * delta2;
        }
    }
    variance /= n - 1;
    long double intrinsic_dimensionality = 0.5f * mean * mean / variance;

    fprintf(stdout, "Elements: %d\nMean: %.4Lf\nVariance: %.4Lf\nIntrinsic Dimensionality: %.4Lf\n",
            sg->nnodes, mean, variance, intrinsic_dimensionality);
    fprintf(stdout, "Min: %.2f, Max: %.2f\n", mini, maxi);
    fflush(stdout);

    DestroySubgraph(&sg);

    return 0;
}

