#define f(i,n)for(i=0;i<n;i++)
char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
main()
{
	f(i,19)gets(b[i]);
	f(i,19)f(j,19)if(b[i][j]-'.')
	{
		C+=b[i][j]=='o'?:-1;
		f(r,4)
		{
			now=0;
			f(k,5)tx=i+d[r]*k,ty=j+d[r+1]*k,now|=tx<0|ty<0|tx>18|ty>18||b[tx][ty]-b[i][j];
			if(!now)
			{
				b[i][j]=='o'?BC++:WC++;
				f(k,5)cnt[i+d[r]*k][j+d[r+1]*k]++;
			}
		}
	}
	f(i,19)f(j,19)if(cnt[i][j]==(C-1?C==BC?WC:-1:WC?-1:BC))exit(!puts("YES"));
	puts("NO");
} ./Main.c:2:16: warning: data definition has no type or storage class
 char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
                ^
./Main.c:2:16: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:2:33: warning: type defaults to ‘int’ in declaration of ‘cnt’ [-Wimplicit-int]
 char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
                                 ^
./Main.c:2:45: warning: type defaults to ‘int’ in declaration of ‘BC’ [-Wimplicit-int]
 char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
                                             ^
./Main.c:2:48: warning: type defaults to ‘int’ in declaration of ‘WC’ [-Wimplicit-int]
 char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
                                                ^
./Main.c:2:51: warning: type defaults to ‘int’ in declaration of ‘C’ [-Wimplicit-int]
 char b[19][22];d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C,i,j,k,r,now,tx,ty;
      ...