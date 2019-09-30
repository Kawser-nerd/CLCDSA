#include <stdio.h>

#define true 1
#define false 0

#define INF 0x3F3F3F3F

typedef unsigned char bool;

int vet[10];
int mat[10][12000000];
int list[12000000];

int precompute(int n)
{
    int i, k;
    int min, nlist = 0, valmin;
    bool end = false;
    
    for(i = 0; i < n; i++)
        mat[i][0] = 0, list[nlist++] = i+1;
    
    for(i = 1; !end  ; i++)
    {
        for(k = 0; k < n; k++)
            mat[k][i-1] = (mat[k][i-1] > 0) ? mat[k][i-1] : vet[k];
        
        for(k = 1, min = 0; k < n; k++)
        {
            if(mat[k][i-1] < mat[min][i-1])
                min = k;
        }
        
        valmin = mat[min][i-1];
        for(k = 0; k < n; k++)
            if(mat[k][i-1] == valmin)
                list[nlist++] = k+1;
        
        for(k = 0; k < n; k++)
            mat[k][i] = mat[k][i-1] - valmin;
        
#ifdef _DEBUG
    printf("(%d) %d\n", min, valmin);
    for(k = 0; k < n; k++)
        printf("%d ", mat[k][i]);
    printf("\n");
#endif
        
        for(k = 0, end = true; k < n && end; k++)
            end = (mat[k][i] == 0);
    }
    
#ifdef _DEBUG
    for(i = 0; i < nlist; i++)
        printf("%d ", list[i]);
    printf("\n");
#endif
    
    return (nlist-n);
}

int main()
{
    int T, cont = 0;
    
    scanf("%d\n", &T);
    while(T--)
    {
        int n, p, nlist;
        int i;
        
        scanf("%d %d\n", &n, &p);
        
        for(i = 0; i < n; i++)
            scanf("%d ", &vet[i]);
        
        nlist = precompute(n);
        
        printf("Case #%d: %d\n", ++cont, list[(p-1)%nlist]);
    }
    
return 0;
}
