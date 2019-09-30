#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *in,*ou;
    long long R,k,N,i,T,j,cur=0ll,temp=0ll,result=0ll,count,lastcur=0ll,a[1000],value[1000],curs[1000];
    if((in=fopen("C-large.in","r"))==NULL)
    {
        printf("Can not open the file");
        exit(0);
    }    
    if((ou=fopen("ou.txt","w"))==NULL)
    {
        printf("Can not open the file");
        exit(0);
    }
    
    fscanf(in,"%I64d",&T);
    for(i=0ll;i<T;i++)
    {
        printf("%I64d",i);
        fscanf(in,"%I64d%I64d%I64d",&R,&k,&N);
        for(j=0ll;j<N;j++) fscanf(in,"%I64d",&a[j]);
        for(j=0ll;j<N;j++)
        {
            temp=0ll;
            cur=j;
            count=0ll;
            while(temp<=k&&count<=N) 
            {     
               temp+=a[cur];
               lastcur=cur;
               cur++;
               if(cur==N) cur-=N;
               count++;
            }  
            temp-=a[lastcur];
            cur=lastcur;
            curs[j]=cur;
            value[j]=temp;
        }
        result=0ll;
        cur=0ll;
        for(j=0ll;j<R;j++)
        {
            result+=value[cur];
            cur=curs[cur];
        }
        fprintf(ou,"Case #%I64d: %I64d\n",i+1,result);
    }
    fclose(in);
    fclose(ou);
    getch();
    return 1;
}
