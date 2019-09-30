//
//	Google CodeJam 2009 - Round 1B, Problem A
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//

// If the following defines are uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST
//#define DUMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct SNODE
{
    double weight;
    char feature[11];
    struct SNODE *pYes;
    struct SNODE *pNo;
} NODE;

NODE *pRoot;

char feature [100][11];
int nFeat;

int L;
int nLine;
char line [10000];
int iLine;
char token [11];

void GetLine ()
{
    int n;

    gets (line);
    n = strlen (line);
    line[n] = ' ';
    line[n+1] = 0;
}

char GetChar (int skip)
{
    char c;

    while (1)
    {
        c = line[iLine++];
        if (c == 0)
        {
            GetLine ();
            iLine = 0;
            nLine++;
            continue;
        }
        if ((c == ' ') || (c == '\n'))
            if (skip)
                continue;
            else
                return ' ';
        return c;
    }
}


int GetToken ()
{
    int i;

    char c = GetChar (1);
    if ((c == '(') || (c == ')'))
    {
        iLine--;
        return 0;
    }
    token[0] = c;
    for (i = 1; i < 10; i++)
    {
        c = GetChar (0);
        if ((c == '(') || (c == ')'))
        {
            iLine--;
            break;
        }
        if (c == ' ')
            break;
        token[i] = c;
    }
    token[i] = 0;
    return 1;
}

double GetWeight ()
{
    GetToken();
    return atof (token);
}

void loadNode (NODE *pNode)
{
    GetChar (1);
    pNode->weight = GetWeight ();
    if (GetToken ())
    {
        strcpy (pNode->feature, token);
        pNode->pYes = (NODE *) malloc (sizeof (NODE));
        pNode->pNo = (NODE *) malloc (sizeof (NODE));
        loadNode (pNode->pYes);
        loadNode (pNode->pNo);
        GetChar (1);
    }
    else
    {
        pNode->feature[0] = 0;
        pNode->pYes = NULL;
        pNode->pNo = NULL;
        GetChar (1);
    }
}

void loadTree ()
{
    GetLine ();
    iLine = 0;
    nLine = 1;

    pRoot = (NODE *) malloc (sizeof (NODE));
    loadNode (pRoot);
    while (nLine < L)
        gets (line);
}

#ifdef DUMP
char sIndent[100] = "";
int iIndent = 0;
void DumpNode (NODE *pNode)
{
    printf ("%s %f %s\n", sIndent, pNode->weight, pNode->feature);
    if (pNode->pYes)
    {
        sIndent[iIndent++] = ' ';
        sIndent[iIndent] = 0;
        DumpNode (pNode->pYes);
        DumpNode (pNode->pNo);
        sIndent[--iIndent] = 0;
    }
}
#endif

void freeNode (NODE *pNode)
{
    if (pNode->pYes)
    {
        freeNode (pNode->pYes);
        freeNode (pNode->pNo);
    }
    free (pNode);
}

int comp (const void *elem1, const void *elem2)
{
    return strcmp (elem1, elem2);
}

int FindFeat (char *f)
{
    int first, last, mid, dif;

    first = 0;
    last = nFeat-1;
    while (last >= first)
    {
        mid = (last+first)/2;
        dif = strcmp (feature[mid], f);
        if (dif == 0)
            return mid;
        else if (dif < 0)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;  // not found
}


void CheckAnimal ()
{
    char name [11];
    int i;
    double p;
    NODE *pNode;

    GetLine ();
    iLine = 0;
    GetToken ();
    strcpy (name, token);
    GetToken ();
    nFeat = atoi (token);
    for (i = 0; i < nFeat; i++)
    {
        GetToken ();
        strcpy (feature[i], token);
    }
    qsort (feature, nFeat, 11, comp);

    p = 1;
    pNode = pRoot;
    while (pNode)
    {
        p = p * pNode->weight;
        if (pNode->feature[0] == 0)
            break;
        if (FindFeat(pNode->feature) == -1)
            pNode = pNode->pNo;
        else
            pNode = pNode->pYes;
    }
    printf ("%f\n", p);
}

void main (void)
{
	int iCase, nCases;
    int i, A;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);

	for (iCase = 1; iCase <= nCases; iCase++)
	{
        scanf ("%d\n", &L);
        loadTree (L);
        #ifdef DUMP
        DumpNode (pRoot);
        #endif
        printf ("Case #%d:\n", iCase);
        scanf ("%d\n", &A);
        for (i = 0; i < A; i++)
            CheckAnimal ();
        freeNode (pRoot);
	}

}
