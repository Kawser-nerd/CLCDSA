#include<stdio.h>
#define SIZE 100
#define SIZE2 1000
int main()
{
    int T,add,i,j,length,num,k;
    long long int sum;
    int index[65];
    char a[SIZE];
    int ascii[SIZE2],de[SIZE];
    scanf("%d",&T);
    for(j=0;j<SIZE2;j++)
    {
        ascii[j]=-1;
    }
    index[0]=0;
    for(j=1;j<65;j++)
    {
        index[j]=j+1;
    }
    for(i=1;i<=T;i++)
    {
        scanf("%s",a);
        for(j=0;j<SIZE2;j++)
        {
            ascii[j]=-1;
        }
        add=0;j=0;
        while(a[j]!='\0')
        {
            /*k=a[j];*/
            if(ascii[a[j]]==-1)
            {
                add++;
                ascii[a[j]]=1;
            }
            j++;
        }
        length=j;j=0;
        while(a[j]!='\0')
        {
            ascii[a[j]]=-1;
            j++;
        }
        /*printf("add=%d\n",add);*/
        if(add==1)/*binary*/
        {
            j=0;sum=0;
            while(a[j]!='\0')
            {
                sum=sum*2+1;
                j++;
            }
            printf("Case #%d: %I64d\n",i,sum);
        }
        else/*two kind up*/
        {
            de[0]=1;ascii[a[0]]=1;num=0;
            for(j=1;j<length;j++)/*decoding*/
            {
                if(ascii[a[j]] == -1)/*new number*/
                {
                    de[j]=index[num];
                    ascii[a[j]]=index[num];
                    num++;
                }
                else
                {
                    de[j]=ascii[a[j]];
                }
            }
            while(a[j]!='\0')
            {
                ascii[a[j]]=-1;
                j++;
            }
            sum=0;
            for(j=0;j<length;j++)
            {
                sum=sum*add+de[j];
                /*printf("%d",de[j]);*/
            }
            printf("Case #%d: %I64d\n",i,sum);
        }
    }
}
