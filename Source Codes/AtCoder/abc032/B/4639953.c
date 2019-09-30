i;j;c;k;main(d,s)char*s;{for(scanf("%s%d",s,&k);d=s[++i];)for(j=0;d&&i-j;c+=!d)d=bcmp(s+i,s+j++,k);printf("%d\n",i<k?0:i-k+1-c);} ./Main.c:1:1: warning: data definition has no type or storage class
 i;j;c;k;main(d,s)char*s;{for(scanf("%s%d",s,&k);d=s[++i];)for(j=0;d&&i-j;c+=!d)d=bcmp(s+i,s+j++,k);printf("%d\n",i<k?0:i-k+1-c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 i;j;c;k;main(d,s)char*s;{for(scanf("%s%d",s,&k);d=s[++i];)for(j=0;d&&i-j;c+=!d)d=bcmp(s+i,s+j++,k);printf("%d\n",i<k?0:i-k+1-c);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 i;j;c;k;main(d,s)char*s;{for(scanf("%s%d",s,&k);d=s[++i];)for(j=0;d&&i-j;c+=!d)d=bcmp(s+i,s+j++,k);printf("%d\n",i<k?0:i-k+1-c);}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 i;j;c;k;main(d,s)char*s;{for(scanf("%s%d",s,&k);d=s[++i];)for(j=0;d&&i-j;c+=!d)d=bcmp(s+...