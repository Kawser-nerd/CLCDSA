#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int p = 10007;

int inv[10008];

int pw(int a,int k,int p){
  int r;
  if(k==0) return 1;
  r=pw(a,k/2,p); r=(r*r)%p;
  if(k%2) r=(r*a)%p;
  return r;
}

int md_get(int a,int b,int p){
  int r=1,i,c=a-b;
  rep(i,a) r= (r*(i+1))%p;
  rep(i,b) r= (r*inv[i+1])%p;
  rep(i,c) r= (r*inv[i+1])%p;
  return r;
}

int pas_mod(int a,int b,int p){
  int i,j,r,k,m;

//  printf("call %d %d",a,b); puts("");

  if(a<b || b<0) return 0;
  if(a<p) return md_get(a,b,p);

  if(a>=p*p){
    int q=p*p;
    return pas_mod(a%q,b%q,p);
  }

  k=a/p; m=b/p;
  i=md_get(k,m,p);
  j=pas_mod(a%p,b%p,p);
  return (i*j)%p;
}

int main(){
  int i,j,k,l,m,n;
  int res,add;
  int x,y,r,rx[20],ry[20];
  int bx,by,dx,dy;
  int size,count=0;
  int use_x[20],use_y[20],use_size;

  rep(i,10008) inv[i]=pw(i,p-2,p);

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&x,&y); x--; y--;
    scanf("%d",&r);
    rep(i,r) {scanf("%d%d",rx+i,ry+i); rx[i]--; ry[i]--;}

    rep(i,r) REP(j,1,r) if(rx[j-1]>rx[j]){
      k=rx[j-1], rx[j-1]=rx[j], rx[j]=k;
      k=ry[j-1], ry[j-1]=ry[j], ry[j]=k;
    }

    res=0;
    rep(k,(1<<r)){
      use_size=0;
      rep(i,r) if(k&(1<<i)) use_x[use_size]=rx[i], use_y[use_size++]=ry[i];
      use_x[use_size] = x; use_y[use_size++]=y;
      
      bx=by=0; add=1;
      rep(i,use_size){
        dx = use_x[i]-bx; dy = use_y[i]-by;
        bx=use_x[i]; by=use_y[i];

        m = (dx+dy)/3;
        if(dx+dy != m*3) {add=0; break;}
        
        add *= pas_mod(m,dx-m,p); add %= p;
      }
      if(use_size%2==0) add *= -1;
      res += add;
    }

    res %= p;
    if(res<0) res+=p;

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
