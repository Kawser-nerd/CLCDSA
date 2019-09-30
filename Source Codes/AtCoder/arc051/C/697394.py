n,a,b,*s=map(int,(input()+' '+input()).split());c=s.sort;c();d,m=s[-1],10**9+7
if~-a:
	while(s[0]<d)*b:s[0]*=a;b-=1;c()
for i in range(b%n):s[i]*=a
c()
for x in s:print(x*pow(a,b//n,m)%m)