from math import sqrt
from collections import defaultdict
a,b = (int(i) for i in input().split())
x,ans,mod = defaultdict(int),1,10**9+7
for i in range(b+1,a+1):
	n = i
	for j in range(2,int(sqrt(i))+1):
		while n%j==0:
			x[j]+=1
			n//=j
		if n<2: break
	if n!=1: x[n]+=1
for i in x.values(): ans = ans*(i+1)%mod
print(ans)