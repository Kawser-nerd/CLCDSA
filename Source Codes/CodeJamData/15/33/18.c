#include<stdio.h>
#include<string.h>
int arr[200],ans;
int possible (int x,int y)
{
    int i,flag=0;
    if(x==0)return 1;
    for(i=y-1;i>=0;i--)
    {
       if(flag)break;                
       if(x<arr[i])continue;
       if(possible(x-arr[i],i))flag=1;
    }
    if(flag)return 1;
    else return 0;
}
void add(int* A,int x)
{
     int m=0,j=ans;
     while(A[m]<x&&A[m]!=0)m++;
     for(j=ans;j>m;j--){A[j]=A[j-1];}
     A[m]=x;
    // printf("\nAdded %d\n",A[m]);
     ans++;
   //  for(j=0;j<ans;j++)printf("%d  ",A[j]);
   //  printf("m=%d\n\n",m);
}
int main()
{
    int C,D,V,T;
    int i,t,j;
    char fileName[]="C-small-attempt1.in",answer[]="CoinAns.in";
    FILE *fp, *fp2;
    fp = fopen(fileName,"r");
    fp2 = fopen(answer,"w");
    fscanf(fp,"%d", &T);
    for(t=0;t<T;t++)
    {
        fscanf(fp,"%d %d %d",&C,&D,&V);
        ans=D;
        for(i=0;i<D;i++)
            fscanf(fp,"%d",&arr[i]);
        for(i=1;i<=V;i++)
            if(possible(i,ans))continue;
            else
            {
                add(arr,i);
          //      getch();
            }    
        fprintf(fp2,"Case #%d: %d\n",t+1,ans-D);
        for(i=0;i<30;i++)arr[i]=0;
    }
    fclose(fp);
    fclose(fp2);
    
    return 0;
}
