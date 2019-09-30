#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node node;
struct node
{
    double weight;
    char *property;
    node *has, *hasnot;
};

node *buildNode(char *prop, double weight)
{
    node *r;
    r = (node*)malloc(sizeof(node));
    assert(r);
    r->weight = weight;
    if (prop != NULL)
    {
        r->property = (char *)malloc(sizeof(char) * (strlen(prop)+1));
        strcpy(r->property, prop);
    }
    else
    {
        r->property = NULL;
    }
    r->has = NULL;
    r->hasnot = NULL;
    return r;
}

void freeNode(node *n)
{
    if (n->has != NULL)
        freeNode(n->has);
    if (n->hasnot != NULL)
        freeNode(n->hasnot);
    free(n);
}

node *root;

node *readTree()
{
    char c;
    int i;
    double weight;
    node *n;
    char prop[11];

    c = getchar();
    while (c == ' ' || c == '\n' || c == '\t')
        c = getchar();

    assert(c == '(');

    scanf("%lf", &weight);

    c = getchar();
    while (c == ' ' || c == '\n' || c == '\t')
        c = getchar();

    if (c == ')')
        return buildNode(NULL, weight);
    prop[0] = c;
    i = 1;
    c = getchar();
    while (!(c == '(' || c == ' ' || c == '\t' || c == '\n'))
    {
        prop[i] = c;
        i++;
        c = getchar();
    }
    prop[i] = '\0';

    n = buildNode(prop, weight);

    if (c == '(')
        ungetc('(', stdin);

    n->has = readTree();
    n->hasnot = readTree();

    c = getchar();
    while (c != ')')
        c = getchar();

    return n;
}

void printTree(node *n)
{
    printf("(%f", n->weight);
    if (n->property != NULL)
    {
        printf(" %s\n", n->property);
        printTree(n->has);
        printTree(n->hasnot);
    }
    printf(")\n");
}

int compfunc(const void *p1, const void *p2)
{
    return strcmp((char*)p1, (char*)p2);
}

int main()
{
    node *root, *cur;
    int tc, T;
    int i,j;
    int numAn;
    int L;
    char features[100][11];
    int nfeat;
    double prob;

    scanf("%d", &T);
    for (tc = 1; tc<=T; tc++)
    {
        scanf("%d", &L);
        root = readTree();
        scanf("%d", &numAn);
        printf("Case #%d:\n", tc);
        for (i=0; i<numAn; i++)
        {
            scanf("%s %d", features[0], &nfeat);
            for (j=0; j<nfeat; j++)
            {
                scanf("%s", features[j]);
            }
            qsort(features, nfeat, sizeof(char) * 11, compfunc);
            cur = root;
            prob = cur->weight;
            while (cur->property != NULL)
            {
                if (bsearch(cur->property, features, nfeat, sizeof(char) * 11, compfunc) != NULL)
                    cur = cur->has;
                else
                    cur = cur->hasnot;
                prob *= (double)cur->weight;
            }
            printf("%f\n", prob);
        }
        freeNode(root);
    }
    return 0;
}
