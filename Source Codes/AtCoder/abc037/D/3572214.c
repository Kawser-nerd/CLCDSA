//r;p;M=1e9+7;a[1<<20];c[1<<20];u[4]={1,-1};f(v,w){int*z=c+v,x=v%w,y=v/w,s,t,d=4;if(*z<0)for(*z=1;d--;~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s,w))%M:0)s=x+u[d],t=y+u[3-d];return*z;}main(){for(;~scanf("%d",a+p);)--c[p++];for(p-=2;p--;)r=(r+f(p,a[1]))%M;printf("%d",r);}
//p;M=1e9+7;long r,c[1<<20];a[1<<20];u[4]={1,-1};f(v,w,s,t,d){if(!c[v])for(c[v]=1,d=4;d--;~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?c[v]+=f(t*w+s,w,0,0,0):0)s=v%w+u[d],t=v/w+u[3-d];return c[v]%=M;}main(){for(;~scanf("%d",a+p++););for(p-=3;p--;)r+=f(p,a[1],0,0,0);printf("%d",r%M);}
long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x,0,0,0):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%=M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i,0,0,0);printf("%d",s%M);} ./Main.c:3:25: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x,0,0,0):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%=M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i,0,0,0);printf("%d",s%M);}
                         ^
./Main.c:3:25: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:3:34: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]={1,-1};w,i;f(v,x,y,r){if(!c[v])for(c[v]=1,r=4;r--;~x&~y&x-w&y-*a&&a[y*w+x+2]>a[v+2]?c[v]+=f(y*w+x,0,0,0):0)x=v%w+d[r],y=v/w+d[3-r];return c[v]%=M;}main(){for(;~scanf("%d",a+i++);w=a[1]);for(i-=3;i--;)s+=f(i,0,0,0);printf("%d",s%M);}
                                  ^
./Main.c:3:34: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:3:46: warning: data definition has no type or storage class
 long s,c[1<<20],M=1e9+7;a[1<<20];d[4]...