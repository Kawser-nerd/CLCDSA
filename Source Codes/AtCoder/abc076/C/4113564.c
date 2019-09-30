#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int K(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    int a,b,i,j,k;
    char A[101],B[101];
    scanf("%s",B);scanf("%s",A);//??S?T
    a=strlen(B); b=strlen(A);//??????????
    
    char D[101][101];
    int C,point,n;
    C=0;point=0;n=0;
    
    
    
    
    if(a>=b)
        
    {
        for(i=a-1;i>=0; i--)
        {
            
            if(B[i]==A[b-1]||B[i]=='?')
            {
                k=i;
                for(j=b-1; j>=0; j--)
                {
                    if(A[j]==B[k]||B[k]=='?')
                        k--;
                    
                    else
                        break;
                    
                }
                if(k==i-b)
                {
                    k=i;
                    strcpy(D[n],B);
                    for(j=b-1; j>=0; j--,k--)
                    {
                        D[n][k]=A[j];
                    }
                    for(j=0; j<a; j++)
                    {
                        if(D[n][j]=='?')
                            D[n][j]='a';
                    }
                    point=1;
                    n++;
                }}}}
    
    
    else

    {
        printf("UNRESTORABLE");
        return 0;
    }
    
    
    
    
    
    if(point!=1)
        printf("UNRESTORABLE");
    else
    {
        qsort(D,n,101*sizeof(char),K);
        printf("%s\n",D[0]);
    }
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",B);scanf("%s",A);//??S?T
     ^
./Main.c:13:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",B);scanf("%s",A);//??S?T
                   ^