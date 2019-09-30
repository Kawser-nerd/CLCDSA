#define M 1<<17
long c,k,n,x[M],y[M],p[M],q[M],u[M],v[M],i,j,m,l,s;main(r){for(scanf("%d%d%d%d",&r,&c,&k,&n);~scanf("%d%d",x+i,y+i);q[y[i++]]++)p[x[i]]++;for(;j++<r;)u[p[j]]++;for(;m++<c;)v[q[m]]++;for(;l<=k;)s+=v[l]*u[k-l++];for(;i--;s-=!r-(r==1))r=p[x[i]]+q[y[i]]-k;printf("%ld\n",s);} ./Main.c:2:52: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long c,k,n,x[M],y[M],p[M],q[M],u[M],v[M],i,j,m,l,s;main(r){for(scanf("%d%d%d%d",&r,&c,&k,&n);~scanf("%d%d",x+i,y+i);q[y[i++]]++)p[x[i]]++;for(;j++<r;)u[p[j]]++;for(;m++<c;)v[q[m]]++;for(;l<=k;)s+=v[l]*u[k-l++];for(;i--;s-=!r-(r==1))r=p[x[i]]+q[y[i]]-k;printf("%ld\n",s);}
                                                    ^
./Main.c: In function ‘main’:
./Main.c:2:52: warning: type of ‘r’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:64: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long c,k,n,x[M],y[M],p[M],q[M],u[M],v[M],i,j,m,l,s;main(r){for(scanf("%d%d%d%d",&r,&c,&k,&n);~scanf("%d%d",x+i,y+i);q[y[i++]]++)p[x[i]]++;for(;j++<r;)u[p[j]]++;for(;m++<c;)v[q[m]]++;for(;l<=k;)s+=v[l]*u[k-l++];for(;i--;s-=!r-(r==1))r=p[x[i]]+q[y[i]]-k;printf("%ld\n",s);}
                                                                ^
./Main.c:2:64: warning: incompatible implicit declaration of built-in function ‘scanf’
...