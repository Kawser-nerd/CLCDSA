#include <stdio.h>

int n,L,A;
int l[1000],r[1000],p;
double w[1000];
char name[1000][100],namelist[1000][100];



build(int x)
{
    char buf[1000];
    char s[1000],t[1000];
    int i;
    
    do{
    fgets(buf,1000,stdin);
    sscanf(buf,"%s",s);
    }while (s[0]==')');
    
    sscanf(buf,"%s%s",&t,s);
    sscanf(t,"(%lf",&w[x]);//printf("###%lf\n",w[x]);
    if (s[0]!=')')
        {for (i=0;s[i];i++) name[x][i]=s[i];name[x][i]=0;}
    
        
    for (i=0;buf[i];i++)
        if (buf[i]==')') return;
        
    p++;l[x]=p;
    build(p);
    p++;r[x]=p;
    build(p);
    
}

main()
{
    int a,i,j,k,B;
    double t;
    char buf[1000];
    
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    scanf("%d",&n);
    
    for (a=0;a<n;a++)
    {
        printf("Case #%d:\n",a+1);
        scanf("%d",&L);   
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(w,0,sizeof(w));
        p=0;
        
        fgets(buf,1000,stdin);//clear
        build(0);
        
        
        while(scanf("%d",&A)!=1) fgets(buf,1000,stdin);
        //scanf("%d",&A);
        //printf("%d\n",A);
        for (i=0;i<A;i++)
        {
            scanf("%s%d",buf,&B);//printf("%s",buf);
            for (j=0;j<B;j++)
                scanf("%s",namelist[j]);
                
            j=0;t=1.0;
            while (l[j]!=0)
            {
                t*=w[j];
                for (k=0;k<B;k++)
                {
                    
                    if (!strcmp(name[j],namelist[k])) break;
                }
                if (k==B||B==0) j=r[j];
                else j=l[j];
            }
            t*=w[j];//printf("##%d\n",B);
            
            
            printf("%lf\n",t);
        }
        
    }
    
    
    return 0;
}
