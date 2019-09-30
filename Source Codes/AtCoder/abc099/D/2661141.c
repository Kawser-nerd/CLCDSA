#include<stdio.h>

int main()
{
    int n,c=30,i,j,k,ans=2147483647;
    scanf("%d %d",&n,&c);
    int board[n][n];
    int iwakan[c][c];
    for(i=0;i<c*c;i++)
    {
        scanf("%d ",&(iwakan[i/c][i%c]));
    }
    for(j=0;j<n*n;j++)
    {
        scanf("%d",&(board[j/n][j%n]));
    }
    int iwaArray[3][30]={0};
    for(i=0;i<c;i++)
    {
        for(j=0;j<(n*n);j++)
        {
            int befcolor=board[j/n][j%n];
            if(befcolor!=(i+1))
            {
                iwaArray[((j/n)+(j%n))%3][i]+=(iwakan[befcolor-1][i]);
            }
            
        }
    }
    for(k=0;k<c*c*c;k++)
    {
        int x=(k/c)/c;
        int y=(k/c)%c;
        int z=k%c;
        if(!((x-y)*(y-z)*(z-x)))continue;
        int kari=iwaArray[0][x]+iwaArray[1][y]+iwaArray[2][z];
        if(kari<ans)ans=kari;
    }
    printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&c);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d ",&(iwakan[i/c][i%c]));
         ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&(board[j/n][j%n]));
         ^