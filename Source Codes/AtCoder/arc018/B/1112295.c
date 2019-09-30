long x[100],y[100],a;i,j,c;main(k){for(gets(x);~scanf("%d%d",x+i,y+i);i++)for(j=i;j--;)for(k=j;k--;c+=~a&1&&a)a=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);printf("%d\n",c);} ./Main.c:1:22: warning: data definition has no type or storage class
 long x[100],y[100],a;i,j,c;main(k){for(gets(x);~scanf("%d%d",x+i,y+i);i++)for(j=i;j--;)for(k=j;k--;c+=~a&1&&a)a=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);printf("%d\n",c);}
                      ^
./Main.c:1:22: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:24: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 long x[100],y[100],a;i,j,c;main(k){for(gets(x);~scanf("%d%d",x+i,y+i);i++)for(j=i;j--;)for(k=j;k--;c+=~a&1&&a)a=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);printf("%d\n",c);}
                        ^
./Main.c:1:26: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 long x[100],y[100],a;i,j,c;main(k){for(gets(x);~scanf("%d%d",x+i,y+i);i++)for(j=i;j--;)for(k=j;k--;c+=~a&1&&a)a=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);printf("%d\n",c);}
                          ^
./Main.c:1:28: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long x[...