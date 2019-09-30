d[]={0,1,0,-1,0};s[99],u[99];g,f,i,j;c(i,r,x,y){for(r=u[i]=1;r<5;x>=0&y>=0&x<10&y<10&s[g=x*10+y]&!u[g]&&c(g))x=i/10+d[r-1],y=i%10+d[r++];}main(){for(;read(0,&g,1);)g-10&&(s[j++]=g-'x',0);for(;i<100;memset(u,!++i,400))if(!s[i]){c(i);g=1;for(j=0;j<100;)g&=!s[j]|u[j++];f|=g;}puts(f?"YES":"NO");} ./Main.c:1:1: warning: data definition has no type or storage class
 d[]={0,1,0,-1,0};s[99],u[99];g,f,i,j;c(i,r,x,y){for(r=u[i]=1;r<5;x>=0&y>=0&x<10&y<10&s[g=x*10+y]&!u[g]&&c(g))x=i/10+d[r-1],y=i%10+d[r++];}main(){for(;read(0,&g,1);)g-10&&(s[j++]=g-'x',0);for(;i<100;memset(u,!++i,400))if(!s[i]){c(i);g=1;for(j=0;j<100;)g&=!s[j]|u[j++];f|=g;}puts(f?"YES":"NO");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:18: warning: data definition has no type or storage class
 d[]={0,1,0,-1,0};s[99],u[99];g,f,i,j;c(i,r,x,y){for(r=u[i]=1;r<5;x>=0&y>=0&x<10&y<10&s[g=x*10+y]&!u[g]&&c(g))x=i/10+d[r-1],y=i%10+d[r++];}main(){for(;read(0,&g,1);)g-10&&(s[j++]=g-'x',0);for(;i<100;memset(u,!++i,400))if(!s[i]){c(i);g=1;for(j=0;j<100;)g&=!s[j]|u[j++];f|=g;}puts(f?"YES":"NO");}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:24: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
 d[]={0,1,0,-1,0}...