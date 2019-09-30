#include<stdio.h>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<memory>
const int oo=0X10101010;
const int maxn=10000;
const int maxm=1000000;
int to[maxm],wei[maxm],back[maxm],adj[maxn],top,S,T,N,our;
void add(int x,int y,int w)
{
    to[top]=y;
    wei[top]=w;
    back[top]=adj[x];
    adj[x]=top++;

    to[top]=x;
    wei[top]=0;
    back[top]=adj[y];
    adj[y]=top++;
}
int lx[maxn],h[maxn],ly[maxn];
bool build()
{
    int p=0,q=0,now;
    memset(h,0,sizeof(h));
    lx[q++]=S;
    h[S]=1;
    while(p<q)
    {
        for(now=adj[lx[p]];now!=-1;now=back[now])
            if(wei[now]>0&&!h[to[now]])
            {
                h[to[now]]=h[lx[p]]+1;
                if(to[now]==T)
                    return true;
                lx[q++]=to[now];
            }
        p++;
    }
    return false;
}
void find()
{
    int q=0,now,i,in;
    lx[q]=S;
    while(q>=0)
    {
        if(lx[q]==T)
        {
            in=0X7FFFFFFF;
            for(i=q;i>0;i--)
                if(wei[ly[i]]<in)
                    in=wei[ly[i]];
            our+=in;
            for(i=q;i>0;i--)
            {
                wei[ly[i]]-=in;
                wei[ly[i]^1]+=in;
                if(!wei[ly[i]])
                    q=i-1;
            }
        }
        else
        {
            for(now=adj[lx[q]];now!=-1;now=back[now])
            {
                if(wei[now]>0&&h[to[now]]==h[lx[q]]+1)
                {
                    q++;
                    ly[q]=now;
                    lx[q]=to[now];
                    break;
                }
            }
            if(now==-1)
            {
                h[lx[q]]=0;
                q--;
            }
        }
    }
}

int main()
{
	freopen("E-large.in","r",stdin);
	freopen("E-large.out","w",stdout);
	int cc,o;
	int kk[4][2]={1,0,0,1,-1,0,0,-1};
	int p,q,ans,i,j,k,n,m,x,y,my[64][64];
	char str[64][64];
	scanf("%d",&cc);
	for(o=1;o<=cc;o++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		p=q=0;
		ans=0;
		memset(my,0XFF,sizeof(my));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(str[i][j]!='.')
				{
					ans+=4;
					if((i+j)&1)
						my[i][j]=p++;
					else
						my[i][j]=q++;
				}
		our=0;
        memset(adj,0XFF,sizeof(adj));
        top=0;
        S=0;
        T=p+q+1;
        N=T+1;
        for(i=0;i<n;i++)
        	for(j=0;j<m;j++)
        		if(str[i][j]!='.')
        		{
        			if((i+j)&1)
        			{
						if(str[i][j]=='#')
							add(S,my[i][j]+1,oo);
						else
							add(S,my[i][j]+1,4);
					}
					else
					{
						if(str[i][j]=='#')
							add(p+my[i][j]+1,T,oo);
						else
							add(p+my[i][j]+1,T,4);
					}
				}
        for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(str[i][j]!='.')
					if((i+j)&1)
						for(k=0;k<4;k++)
						{
							x=kk[k][0]+i;
							y=kk[k][1]+j;
							if(x>=0&&x<n&&y>=0&&y<m)
								if(my[x][y]!=-1)
									add(my[i][j]+1,p+my[x][y]+1,2);
						}
		while(build())
            find();
    	printf("Case #%d: %d\n",o,ans-our);
	}
	return 0;
}



















		
	
