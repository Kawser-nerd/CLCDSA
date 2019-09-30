#include<stdio.h>
#include<math.h>
int main(void)
{
    int T,iter,N,M,K,border,total,inner,result,min_m,min_m_val,max_m,max_m_val,diff,diffdiv,diffmod;
    FILE *fp,*fp1;
    fp = fopen("input","r");
    fp1 = fopen("output.txt","w");
    fscanf(fp,"%d",&T);
    printf("%dtest\n",T);
    for(iter=0;iter<T;iter++)
    {
        result=0;
        fscanf(fp,"%d",&N);
        fscanf(fp,"%d",&M);
        fscanf(fp,"%d",&K);
        //printf("%d %d %d\n",N,M,K);
        if(N==1 || N==2 || M==1 || M==2)
            border = N*M;
        else
            border = (2*N)+(2*M)-4;
        total = N*M;
        inner = total-border;
        if(inner==0)
            result = K;
        else
        {
            min_m = 5;
            min_m_val = 4;
            max_m = total-4;
            max_m_val = max_m - inner;
            if(K<min_m)
                result = K;
            else if(K>max_m)
                result = K-max_m+max_m_val;
            else
            {
                printf("different result");
                diff=max_m-K;
                result = max_m_val-(diff/2);
            }
        }
        //printf("%dinner %dborder %dtotal %dminm %dmaxm\n",inner,border,total,min_m_val,max_m_val);
        fprintf(fp1,"Case #%d: %d\n",iter+1,result);
    }
   return 0;
}
