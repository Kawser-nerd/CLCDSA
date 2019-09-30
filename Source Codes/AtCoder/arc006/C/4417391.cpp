#include <cstdio>
#define EMPTY_FLAG 0
int main(void)
{
    int i,j,trunk,N,count=0,*pile;
    scanf("%d",&N);
    pile=new int [N];
    for(i=0;i<N;i++)
        pile[i]=EMPTY_FLAG;
    for(i=0;i<N;i++)
    {
        scanf("%d",&trunk);
        for(j=0;j<N;j++)
        {
            if(trunk<=pile[j])
            {
                pile[j]=trunk;
                break;
            }
            if(pile[j]==EMPTY_FLAG)
            {
                pile[j]=trunk;
                count++;
                break;
            }
        }
    }
    delete [] pile;
    printf("%d\n",count);
    return 0;
}