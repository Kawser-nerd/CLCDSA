from math import sqrt
from itertools import combinations
n,k = (int(i) for i in input().split())
a,num,mod,ans = [],k,10**9+7,0
for i in range(1,int(sqrt(k))+1):
	if k==i**2: a.append(i)
	elif k%i==0: a.extend([i,k//i])
def fact(x):
	L,i = [],2
	while i**2<=x:
		while x%i==0:
			x = x//i
			L.append(i)
		i += 1
	if x>1: L.append(x)
	return list(set(L))
def pri(x,y):
	f,p = fact(x),(1+y)*y//2
	for i in range(1,len(f)+1):
		for j in combinations(f,i):
			num = 1
			for k in j: num *= k
			if num<=y and i%2==1: p -= (num+(y//num)*num)*(y//num)//2
			elif num<=y: p += (num+(y//num)*num)*(y//num)//2
	return p%mod
for i in a: ans = (ans+k*pri(k//i,n//i))%mod
print(ans)