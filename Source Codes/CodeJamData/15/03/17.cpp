#include <iostream>
#include <stdio.h>

#define L_MAX 10000

using namespace std;

int convert(char c);
int multiply(int p, int q);

int main()
{
    FILE* reader = fopen("C-large.in", "r");
    int T;
    fscanf(reader, "%d", &T);
    //printf("%d", T);
    for (int t=1; t<=T; t++) {
        int L;
        long long X;
        fscanf (reader, "%d %lld", &L, &X);

        X = min(X,12+X%4);
        char input[20*L_MAX];

        char c;
        fscanf(reader, "%c", &c);
        for(int i=0; i<L; i++) {
            fscanf(reader, "%c", &c);
            for (int x=0; x<X; x++)
                input[x*L+i]=convert(c);
        }
        int total_length = X*L;
        /* for(int i=0; i<total_length; i++)
            printf("%d", input[i]);
        printf("\n");*/

        int find_i, find_j, find_k;
        int val = 1;
        for (find_i=0; find_i<total_length; find_i++) {
            val=multiply(val, input[find_i]);
            //printf("%d", val);
            if(val==convert('i'))
                break;
        }
        //printf("find_i=%d\n", find_i);

        val = 1;
        for (find_j=find_i+1; find_j<total_length; find_j++) {
            val=multiply(val, input[find_j]);
            if(val==convert('j'))
                break;
        }

        val = 1;
        for (find_k=find_j+1; find_k<total_length; find_k++) {
            val=multiply(val, input[find_k]);
        }

        if(val == convert('k'))
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
    return 0;
}

int convert(char c)
{
    if (c=='i')
        return 2;
    else if (c=='j')
        return 3;
    else if(c=='k')
        return 4;
    else
    {
        return -1;
        printf("Error (convert)\n");
    }
}

int multiply(int p, int q)
{
    int m=1;
    if (p<0) {
        m=-m;
        p=-p;
    }
    if (q<0)
    {
        m=-m;
        q=-q;
    }

    if(p==1)
        m*=q;
    else if (q==1)
        m*=p;
    else if (p==q)
        m*=-1;
    else if (p==convert('i') && q==convert('j'))
        m*=convert('k');
    else if (p==convert('j') && q==convert('i'))
        m*=-convert('k');
    else if (p==convert('i') && q==convert('k'))
        m*=-convert('j');
    else if (p==convert('k') && q==convert('i'))
        m*=convert('j');
    else if (p==convert('j') && q==convert('k'))
        m*=convert('i');
    else if (p==convert('k') && q==convert('j'))
        m*=-convert('i');
    else
    {
        return -1;
        printf("Error (mult)\n");
    }

    return m;
}
