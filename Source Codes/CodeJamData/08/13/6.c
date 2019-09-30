#include<stdio.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define BIG_INT_SIZE 50
#define BIG_INT_BASE 10000000LL
#define BIG_INT_DIGITS 7
#define BIG_INT_CHAR_SIZE 700

#define ll long long

typedef struct big_integer{ll a[BIG_INT_SIZE];}bigInt;

int bigIntToChar(bigInt a,char ret[]);
void printBigInt(bigInt a);
void putBigInt(bigInt a);


bigInt bigIntZero(){
  bigInt a; int i;
  rep(i,BIG_INT_SIZE) a.a[i]=0;
  return a;
}

bigInt bigIntOne(){
  bigInt a; int i;
  REP(i,1,BIG_INT_SIZE) a.a[i]=0; a.a[0]=1;
  return a;
}

bigInt bigIntOrder(bigInt a){
  int i; ll k;
  REP(i,1,BIG_INT_SIZE) if(a.a[i-1]<0 || a.a[i-1]>=BIG_INT_BASE){
    k=a.a[i-1]/BIG_INT_BASE; a.a[i-1]-=k*BIG_INT_BASE;
    if(a.a[i-1]<0) k--, a.a[i-1]+=BIG_INT_BASE; a.a[i]+=k;
  }
  if(a.a[BIG_INT_SIZE-1]<0){
    rep(i,BIG_INT_SIZE) a.a[i]=-a.a[i]; a=bigIntOrder(a);
    rep(i,BIG_INT_SIZE) a.a[i]=-a.a[i];
  }
  return a;
}

bigInt llToBigInt(ll a){
  bigInt c; int i;
  REP(i,1,BIG_INT_SIZE) c.a[i]=0; c.a[0]=a;
  return bigIntOrder(c);
}

int bigIntGreaterThan(bigInt a,bigInt b){
  int i;
  for(i=BIG_INT_SIZE-1;i>=0;i--){
    if(a.a[i]>b.a[i]) return 1;
    if(a.a[i]<b.a[i]) return 0;
  }
  return 0;
}

int bigIntIsZero(bigInt a){
  int i; rep(i,BIG_INT_SIZE) if(a.a[i]) return 0; return 1;
}

bigInt bigIntPlus(bigInt a,bigInt b){
  int i; bigInt c;
  rep(i,BIG_INT_SIZE) c.a[i]=a.a[i]+b.a[i];
  return bigIntOrder(c);
}

bigInt bigIntMinus(bigInt a,bigInt b){
  int i; bigInt c;
  rep(i,BIG_INT_SIZE) c.a[i]=a.a[i]-b.a[i];
  return bigIntOrder(c);
}

bigInt bigIntMultipleLL(bigInt a,ll b){
  int i; rep(i,BIG_INT_SIZE) a.a[i]*=b;
  return bigIntOrder(a);
}

bigInt bigIntMultiple(bigInt a,bigInt b){
  int i,j,ii,jj; bigInt c;
  for(ii=BIG_INT_SIZE-1;ii;ii--) if(a.a[ii]) break; ii++;
  if(ii==1) return bigIntMultipleLL(b,a.a[0]);
  for(jj=BIG_INT_SIZE-1;jj;jj--) if(b.a[jj]) break; jj++;
  if(jj==1) return bigIntMultipleLL(a,b.a[0]);
  rep(i,BIG_INT_SIZE) c.a[i]=0;
  rep(i,ii)if(a.a[i])for(j=0;j<jj&&i+j+1<BIG_INT_SIZE;j++) c.a[i+j]+=a.a[i]*b.a[j];
  return bigIntOrder(c);
}

void bigIntDivisionsLL(bigInt a,ll b,bigInt *c,ll *d){
  int i;
  rep(i,BIG_INT_SIZE) c->a[i]=a.a[i];
  for(i=BIG_INT_SIZE-1;i;i--)
    c->a[i-1]+=(c->a[i]%b)*BIG_INT_BASE, c->a[i]/=b;
  *d = c->a[0]%b; c->a[0]/=b;
}

/* c=a/b, d=a%b */
void bigIntDivisions(bigInt a,bigInt b,bigInt *c,bigInt *d){
  int i,j,s,sa,sb; ll ma,mb,mc; bigInt tmp;
  sa=bigIntSign(a); sb=bigIntSign(b);
  if(sa==-1) a=bigIntMultipleLL(a,-1);
  if(sb==-1) b=bigIntMultipleLL(b,-1);
  
  for(j=BIG_INT_SIZE-1;j;j--) if(b.a[j]) break;
  if(!j){
    REP(i,1,BIG_INT_SIZE) d->a[i]=0;
    bigIntDivisionsLL(a,b.a[0],c,&(d->a[0]));
  }else{
    for(i=BIG_INT_SIZE-1;i;i--) if(a.a[i]) break;
    s=i-j; if(s<0) s=0;
    rep(i,BIG_INT_SIZE) c->a[i]=0;
    while(s>=0){
      ma=0; mb=BIG_INT_BASE-1;
      while(ma!=mb){
        mc = (ma+mb)/2 + (ma+mb)%2;
        c->a[s]=mc; tmp=bigIntMultiple(*c,b);
        if(bigIntGreaterThan(tmp,a)) mb=mc-1; else ma=mc;
      }
      c->a[s]=ma; s--;
    }
    tmp = bigIntMultiple(b,*c);
    *d = bigIntMinus(a,tmp);
  }

  if(sa==-1 && sb==-1){
    *d=bigIntMultipleLL(*d,-1);
  } else if(sa==-1 && sb!=-1){
    *c=bigIntMultipleLL(*c,-1);
    *d=bigIntMultipleLL(*d,-1);
  } else if(sa!=-1 && sb==-1){
    *c=bigIntMultipleLL(*c,-1);
  }
}

bigInt bigIntDivision(bigInt a,bigInt b){
  bigInt c,d;
  bigIntDivisions(a,b,&c,&d);
  return c;
}

bigInt bigIntModular(bigInt a,bigInt b){
  bigInt c,d;
  bigIntDivisions(a,b,&c,&d);
  return d;
}

int bigIntSign(bigInt a){
  int i;
  for(i=BIG_INT_SIZE-1;i>=0;i--) if(a.a[i]){
    if(a.a[i]<0) return -1; else return 1;
  }
  return 0;
}

bigInt bigIntAbs(bigInt a){
  if(bigIntSign(a)==-1) return bigIntMultipleLL(a,-1LL); return a;
}

bigInt bigIntGCD(bigInt a,bigInt b){
  if(bigIntSign(a)==-1) a=bigIntMultipleLL(a,-1);
  if(bigIntSign(b)==-1) b=bigIntMultipleLL(b,-1);
  if(bigIntIsZero(a)) return b;
  return bigIntGCD(bigIntModular(b,a),a);
}

int bigIntToChar(bigInt a,char ret[]){
  int i,j,s=0,len=0; char ct[BIG_INT_CHAR_SIZE]; ll lt;
  if(bigIntSign(a)==-1){
    ret[0]='-'; len=bigIntToChar(bigIntMultipleLL(a,-1LL),ret+1); return len+1;
  }
  rep(i,BIG_INT_SIZE){
    lt=a.a[i]; rep(j,BIG_INT_DIGITS) ct[s++]=lt%10, lt/=10;
  }
  j=0;
  while(s--){
    if(ct[s]) j=1;
    if(j) ret[len++]=ct[s]+'0';
  }
  if(!len) ret[len++]='0';
  ret[len]='\0'; return len;
}

void printBigInt(bigInt a){
  int i,k; char tmp[BIG_INT_CHAR_SIZE];
  k=bigIntToChar(a,tmp); rep(i,k) putchar(tmp[i]);
}

void putBigInt(bigInt a){
  char tmp[BIG_INT_CHAR_SIZE];
  bigIntToChar(a,tmp); puts(tmp);
}


bigInt pw(bigInt a,int k){
  bigInt r;
  if(k==0) return bigIntOne();
  r=pw(a,k/2);
  r=bigIntMultiple(r,r);
  if(k%2) r=bigIntMultiple(r,a);
  return r;
}

char *rt1_char = "1000000000000000000000000000000000000000000000000000000000000000000000000000";
char *rt5_char = "2236067977499789696409173668731276235440618359611525724270897245410520925638";
bigInt rt1,rt5;

int main(){
  int i,j,k,l,m,n;
  bigInt a,b,t;
  bigInt c[40][40];

  c[0][0]=bigIntOne(); REP(j,1,40) c[0][j]=bigIntZero();
  REP(i,1,40){
    c[i][0]=bigIntOne(); REP(j,1,40) c[i][j]=bigIntPlus(c[i-1][j-1],c[i-1][j]);
  }

  rt1 = rt5 = bigIntZero();
  for(i=0;;i++){
    if(rt1_char[i]=='\0') break;
    rt1 = bigIntMultipleLL(rt1,10);
    rt1 = bigIntPlus( rt1, llToBigInt( rt1_char[i]-'0' ) );
  }
  for(i=0;;i++){
    if(rt5_char[i]=='\0') break;
    rt5 = bigIntMultipleLL(rt5,10);
    rt5 = bigIntPlus( rt5, llToBigInt( rt5_char[i]-'0' ) );
  }

  int size,count=0;
  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    printf("Case #%d: ",++count);

    a=b=bigIntZero();
    rep(i,n+1){
      if(i%2){
        t = pw( llToBigInt(5), i/2 );
        t = bigIntMultiple( t, pw(llToBigInt(3),n-i) );
        t = bigIntMultiple( t, c[n][i] );
        a = bigIntPlus(a,t);
      } else {
        t = pw( llToBigInt(5), i/2 );
        t = bigIntMultiple( t, pw(llToBigInt(3),n-i) );
        t = bigIntMultiple( t, c[n][i] );
        b = bigIntPlus(b,t);
      }
    }

    a=bigIntMultiple(a,rt5);
    b=bigIntMultiple(b,rt1);
    a=bigIntPlus(a,b);
    a=bigIntDivision(a,rt1);
    
    printf("%03lld\n",a.a[0]%1000LL);
  }
  
  return 0;
}
