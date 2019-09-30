#include<iostream>  
#include<algorithm> 
#include<cstdio>  
#include<cstring>    
using namespace std;  
int n,m,a,b,c,d;
long long sum,ans; 
struct node  
{  
    int w,v;  
}g[110];  
  
bool cmp(node a,node b)  
{  
    return a.v>b.v;  
}  
node A[110],B[110],C[110],D[110];  
  
long long swa[110],swb[110],swc[110],swd[110];  
long long sva[110],svb[110],svc[110],svd[110]; 
  
int main()  
{  
        cin>>n>>m; 
        for(int i=1;i<=n;i++)  
        {  
            cin>>g[i].w>>g[i].v;  
            if(g[i].w==g[1].w) A[++a]=g[i];  
            if(g[i].w==g[1].w+1) B[++b]=g[i];  
            if(g[i].w==g[1].w+2) C[++c]=g[i];  
            if(g[i].w==g[1].w+3) D[++d]=g[i];  
        }  
        sort(A+1,A+a+1,cmp);  
        sort(B+1,B+b+1,cmp);  
        sort(C+1,C+c+1,cmp);  
        sort(D+1,D+d+1,cmp);  
        
        for(int i=1;i<=a;i++)  
        {  
            swa[i]=swa[i-1]+A[i].w;  
            sva[i]=sva[i-1]+A[i].v;  
        }  
        for(int i=1;i<=b;i++)  
        {  
            swb[i]=swb[i-1]+B[i].w;  
            svb[i]=svb[i-1]+B[i].v;  
        }  
        for(int i=1;i<=c;i++)  
        {  
            swc[i]=swc[i-1]+C[i].w;  
            svc[i]=svc[i-1]+C[i].v;  
        }  
        for(int i=1;i<=d;i++)  
        {  
            swd[i]=swd[i-1]+D[i].w;  
            svd[i]=svd[i-1]+D[i].v;  
        }  
    
        for(int i=0;i<=a;i++)  
        for(int j=0;j<=b;j++)  
        for(int k=0;k<=c;k++)  
        for(int l=0;l<=d;l++)  
        {  
        sum=swa[i]+swb[j]+swc[k]+swd[l];  
        if(sum<=m)  
        ans=max(ans,sva[i]+svb[j]+svc[k]+svd[l]);  
              
        }  
        cout<<ans<<endl;  
    
  
    return 0;  
}