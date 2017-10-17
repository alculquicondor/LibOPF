#include "OPF.h"

int main(int argc, char **argv){
    fflush(stdout);
    fprintf(stdout, "\nProgram that removes outliers from an input set\n");
    fprintf(stdout, "\n"); fflush(stdout);

    if (argc != 4) {
        fprintf(stderr, "usage opf_dimensionality <P1> <p> <P2>\n\n");
        fprintf(stderr, "P1: Dataset in the OPF file format\n");
        fprintf(stderr, "p: percentage to remove\n");
        fprintf(stderr, "P2: output filename\n");
        exit(-1);
    }
    float p;
    sscanf(argv[2], "%f", &p);

    Subgraph *sg = ReadSubgraph(argv[1]);

    char *remove = malloc((size_t)sg->nnodes);
    memset(remove, 0, (size_t)sg->nnodes);
    int f, i;
    for (f = 0; f < sg->nfeats; ++f) {
        float min_val = INFINITY;
        float max_val = -INFINITY;
        for (i = 0; i < sg->nnodes; ++i) {
            min_val = MIN(min_val, sg->node[i].feat[f]);
            max_val = MAX(max_val, sg->node[i].feat[f]);
        }
        fprintf(stdout, "Min: %.2f    Max: %.2f\n", min_val, max_val);
        float per = (max_val - min_val) * p;
        for (i = 0; i < sg->nnodes; ++i) {
            if (sg->node[i].feat[f] > max_val - per || sg->node[i].feat[f] < min_val + per)
                remove[i] = 1;
        }
    }
    int cnt = 0;
    for (i = 0; i < sg->nnodes; ++i)
        if (!remove[i])
            ++cnt;

    fprintf(stdout, "Initial: %d  Final: %d\n", sg->nnodes, cnt);

    Subgraph *sg_clean = CreateSubgraph(cnt);
    sg_clean->nfeats = sg->nfeats;
    sg_clean->nlabels = sg->nlabels;

    cnt = 0;
    for (i = 0; i < sg->nnodes; ++i)
        if (!remove[i])
            CopySNode(&sg_clean->node[cnt++], &sg->node[i], sg->nfeats);

    WriteSubgraph(sg_clean, argv[3]);

    DestroySubgraph(&sg);
    DestroySubgraph(&sg_clean);

    return 0;
}

