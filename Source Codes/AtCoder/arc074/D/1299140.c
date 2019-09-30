#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int ta[20010],to[4000010],nt[4000010],co[4000010],F[20010],it[20010],l[20010];
void mklsd(int v,int e,int *a,int *b,int *c){
  int i;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i]=ta[a[i]];
    to[i]=b[i];
    co[ta[a[i]]=i]=c[i];
  }
}
int MF(int e,int s,int t,int min){
  if(s==t)return min;
  int i,r;
  for(;it[s]+1;it[s]=nt[it[s]]){
    if(co[it[s]]==0||l[s]>=l[to[it[s]]])continue;
    r=MF(e,to[it[s]],t,MIN(min,co[it[s]]));
    co[it[s]]-=r;
    co[(it[s]+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
//?????
int q[4000010];
//??v??e?????s??g???
int maxf(int v,int e,int s,int g){
  int i,a=0,t,r,c=3;
  while(1){
    for(i=t=0;i<v;i++)l[i]=0;
    for(r=l[q[0]=s]=1;r-t;t++){
      for(i=ta[q[t]];i+1;i=nt[i]){
	if(co[i]&&l[to[i]]==0)l[q[r++]=to[i]]=l[q[t]]+1;
      }
    }
    if(l[g]==0)return a;
    for(i=0;i<v;i++)it[i]=ta[i];
    while(r=MF(e,s,g,1e9))a+=r;
  }
}
  int h,w,s,g,r=0,a[2000010],b[2000010],c[2000010],e=0,ans,i,j,k,d[110][110];
int main(){
  char p;
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      d[i][j]=-1;
      scanf(" %c",&p);
      if(p=='S')s=r;
      if(p=='T')g=r;
      if(p-'.')d[i][j]=r++;
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(d[i][j]<0)continue;
      a[e  ]=d[i][j]+r;
      b[e  ]=d[i][j];
      c[e++]=d[i][j]==s||d[i][j]==g?1e9:1;
      for(k=0;k<h;k++){
	if(d[k][j]<0||i==k)continue;
	if((d[i][j]==s&&d[k][j]==g)||(d[i][j]==g&&d[k][j]==s))goto END;
	a[e  ]=d[i][j];
	b[e  ]=d[k][j]+r;
	c[e++]=1e9;
      }
      for(k=0;k<w;k++){
	if(d[i][k]<0||k==j)continue;
	if((d[i][j]==s&&d[i][k]==g)||(d[i][j]==g&&d[i][k]==s))goto END;
	a[e  ]=d[i][j];
	b[e  ]=d[i][k]+r;
	c[e++]=1e9;
      }
    }
  }
  mklsd(r*2,e,a,b,c);
  printf("%d\n",maxf(r*2,e,s,g));
  return 0;
 END:;
  printf("-1\n");//printf("%d %d %d\n",i,j,k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:49:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf(" %c",&p);
       ^