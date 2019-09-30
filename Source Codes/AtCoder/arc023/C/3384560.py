n = int(input())
a = [int(i) for i in input().split()]
m,mod,ans = 0,10**9+7,1
def power(n,k):
	if k==1: return n
	elif k%2==0: return power((n**2)%mod,k//2)
	else: return (n*power(n,k-1))%mod
for i in range(n):
	if a[i]+1 and m:
		p,p2,x = 1,1,a[i]-s+1
		for j in range(x,x+m): p = (p*j)%mod
		for j in range(1,m+1): p2 = (p2*j)%mod
		ans,m,s = (ans*p*power(p2,mod-2))%mod,0,a[i]
	elif a[i]+1: s = a[i]
	elif m: m+=1
	else: m = 1
print(ans)