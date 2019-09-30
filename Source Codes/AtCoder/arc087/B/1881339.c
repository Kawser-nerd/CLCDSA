d[4][1<<16];*s=*d,*t=d+1;w;c;f;p=2e4;i;main(a){s[p]=d[2][p]=1;do{if(a=getchar()-70){for(i=1e4;i<3e4;i++)t[i-c]|=s[i]&&f,t[i+c]|=s[i];w=2-w;s=d[w+f%2];memset(t=d[w?++f%2+w:-~f%2+w],0,2e5);c=-1;}c++;}while(a>=0);scanf("%d%d",&a,&c);puts(d[f%2][p+a]&&d[2+(f+!!w&1)][p+c]?"Yes":"No");} ./Main.c:1:1: warning: data definition has no type or storage class
 d[4][1<<16];*s=*d,*t=d+1;w;c;f;p=2e4;i;main(a){s[p]=d[2][p]=1;do{if(a=getchar()-70){for(i=1e4;i<3e4;i++)t[i-c]|=s[i]&&f,t[i+c]|=s[i];w=2-w;s=d[w+f%2];memset(t=d[w?++f%2+w:-~f%2+w],0,2e5);c=-1;}c++;}while(a>=0);scanf("%d%d",&a,&c);puts(d[f%2][p+a]&&d[2+(f+!!w&1)][p+c]?"Yes":"No");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:13: warning: data definition has no type or storage class
 d[4][1<<16];*s=*d,*t=d+1;w;c;f;p=2e4;i;main(a){s[p]=d[2][p]=1;do{if(a=getchar()-70){for(i=1e4;i<3e4;i++)t[i-c]|=s[i]&&f,t[i+c]|=s[i];w=2-w;s=d[w+f%2];memset(t=d[w?++f%2+w:-~f%2+w],0,2e5);c=-1;}c++;}while(a>=0);scanf("%d%d",&a,&c);puts(d[f%2][p+a]&&d[2+(f+!!w&1)][p+c]?"Yes":"No");}
             ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 d[4][1<<16];*s=*d,*t=d+1;w;c;f;p=2e4;i;main(a){s[p]=d[2][p]=1;do{if(a=getchar()-70){for(i=1e4;i<3e4;i++)t[i-c]|=s[i]&&f,t[i+c]|=s[i...