using System.Linq;
using static System.Console;
class K
{
int[]G=>ReadLine().Split().Select(i=>int.Parse(i)-1).ToArray();
int N;
static void Main()=>new K().Z();
void Z()
{
var I=G;
N=I[0]+1;
WriteLine(string.Join(" ",C(G,G,I[1]).Select(i=>i+1)));
}
int[]C(int[]p,int[]q,int K)
{
int[]P=I(p),Q=I(q),x=E(M(q,P,Q,p),K/6),y=I(x);
switch(K%6)
{
case 0:return M(x,p,y);
case 1:return M(x,q,y);
case 2:return M(x,q,P,y);
case 3:return M(x,q,P,Q,y);
case 4:return M(x,q,P,Q,p,Q,y);
default:return M(x,q,P,Q,p,p,Q,y);
}
}
int[]I(int[]a)
{
var c=new int[N];
for(var i=0;i<N;i++)c[a[i]]=i;
return c;
}
int[]M(int[]a,int[]b){var p=new int[N];for(var i=0;i<N;i++)p[i]=a[b[i]];return p;}
int[]M(params int[][]a)=>a.Aggregate(M);
int[]E(int[]a,int b)
{
var p=new int[N];
var f=new int[N];
var l=new int[N];
for(var i=0;i<N;i++)
if(f[i]<1)
{
int x=i,C=0;
while(f[x]<1){l[C++]=(x);f[x]=1;x=a[x];}
for(var j=0;j<C;j++)p[l[j]]=l[(j+b)%C];
}
return p;
}
}