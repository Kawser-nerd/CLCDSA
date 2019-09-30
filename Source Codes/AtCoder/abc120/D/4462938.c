#define N 100001 
long p[N],r[N],n,m,i,b[N],a[N][2],c,d;int f(int x){if(p[x]==x)return x;return p[x]=f(p[x]);}int u(int x,int y){x=f(x);y=f(y);p[x]=y;r[y]+=r[x];r[x]=r[y];}int main(){scanf("%ld%ld",&n,&m);for(i=0;i<m;i++)scanf("%d%d",a[i],&a[i][1]);b[m]=n*(n-1)/2;for(i=0;i<N;i++){p[i]=i;r[i]=1;};for(i=m-1;i>0;i--){c=a[i][0],d=a[i][1];b[i]=b[i+1];if(f(c)!=f(d)){b[i]-=r[f(c)]*r[f(d)];u(c,d);}}for(i=1;i<=m;i++)printf("%ld\n",b[i]);} ./Main.c: In function ‘main’:
./Main.c:2:166: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long p[N],r[N],n,m,i,b[N],a[N][2],c,d;int f(int x){if(p[x]==x)return x;return p[x]=f(p[x]);}int u(int x,int y){x=f(x);y=f(y);p[x]=y;r[y]+=r[x];r[x]=r[y];}int main(){scanf("%ld%ld",&n,&m);for(i=0;i<m;i++)scanf("%d%d",a[i],&a[i][1]);b[m]=n*(n-1)/2;for(i=0;i<N;i++){p[i]=i;r[i]=1;};for(i=m-1;i>0;i--){c=a[i][0],d=a[i][1];b[i]=b[i+1];if(f(c)!=f(d)){b[i]-=r[f(c)]*r[f(d)];u(c,d);}}for(i=1;i<=m;i++)printf("%ld\n",b[i]);}
                                                                                                                                                                      ^
./Main.c:2:166: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:2:166: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:2:210: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long p[N],r[N],n,m,i,b...