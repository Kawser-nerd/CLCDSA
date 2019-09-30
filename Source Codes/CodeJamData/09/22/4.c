#include <stdio.h>


int n;
main()
{
    int i,j,k,l,m,t;
    char buf[50];
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
    {
        scanf("%s",buf);    
        
        for (j=0;buf[j];j++);t=j;
        
        for (j--;j>0;j--)
        {
            if (buf[j-1]<buf[j]) break;
        }
        
        if (j!=0)
        {
            for (k=j;buf[k];k++)
            {
                if (buf[k]<=buf[j-1]) break;
            }
            m=buf[k-1];buf[k-1]=buf[j-1];buf[j-1]=m;
            //printf("%s\n",buf);
            
            for (k=0;k<t-j;k++)
            {
                for (l=j;l<t-k-1;l++)
                    if (buf[l]>buf[l+1]) {m=buf[l+1];buf[l+1]=buf[l];buf[l]=m;}
                
            }
            
        }
        if (j==0)
        {
            for (k=t-1;k>=0;k--)
            {
                if (buf[k]!='0') break;
            }
            m=buf[k];buf[k]=buf[0];buf[0]=m;
            buf[t]='0';buf[t+1]=0;
            
            for (k=0;k<t;k++)
            {
                for (l=1;l<t-k;l++)
                    if (buf[l]>buf[l+1]) {m=buf[l+1];buf[l+1]=buf[l];buf[l]=m;}
                
            }
            
            
        }
        
        
        
        printf("Case #%d: %s\n",i+1,buf);
    }
    
    return 0;
}
