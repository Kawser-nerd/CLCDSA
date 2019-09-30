long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i);printf("%d",s%M);} ./Main.c:1:25: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i);printf("%d",s%M);}
                         ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:34: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i);printf("%d",s%M);}
                                  ^
./Main.c:1:34: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:46: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(...