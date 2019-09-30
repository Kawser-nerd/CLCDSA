#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 100000

void intSort(int d[],int s){
  int i,j; int key,t;
  if(s<=1) return;

  key=(d[0]+d[s-1])/2; i=-1; j=s;
  for(;;){
    while(d[++i] < key); while(d[--j] > key);
    if(i>=j) break; t=d[i]; d[i]=d[j]; d[j]=t;
  }
  intSort(d,i); intSort(d+j+1,s-j-1);
}

int main(){
  int i,j,k,l,m,n,t;

  int a_n, b_n;
  int a_st[200],a_ed[200],b_st[200],b_ed[200];
  int a,b,c,d;
  int a_s, b_s, a_use, b_use;
  
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&t);
    scanf("%d%d",&a_n,&b_n);
    rep(i,a_n){
      scanf("%d:%d",&j,&k); a_st[i]=j*60+k;
      scanf("%d:%d",&j,&k); a_ed[i]=j*60+k+t;
    }
    rep(i,b_n){
      scanf("%d:%d",&j,&k); b_st[i]=j*60+k;
      scanf("%d:%d",&j,&k); b_ed[i]=j*60+k+t;
    }

    a_s = b_s = 0; a_use = b_use = 0;
    intSort(a_st,a_n); intSort(a_ed,a_n); intSort(b_st,b_n); intSort(b_ed,b_n);
    a_st[a_n]=a_ed[a_n]=b_st[b_n]=b_ed[b_n]=INF;
    
    a=b=c=d=0;
    for(;;){
      t=INF;
      if(a_st[a]<t) t= a_st[a];
      if(a_ed[b]<t) t= a_ed[b];
      if(b_st[c]<t) t= b_st[c];
      if(b_ed[d]<t) t= b_ed[d];
      if(t==INF) break;

      if(a_ed[b]==t){b++; b_s++; continue;}
      if(b_ed[d]==t){d++; a_s++; continue;}
      if(a_st[a]==t){a++; if(a_s) a_s--; else a_use++; continue;}
      if(b_st[c]==t){c++; if(b_s) b_s--; else b_use++; continue;}
    }

    printf("Case #%d: %d %d\n",++count,a_use,b_use);
  }
  
  return 0;
}
