n,k = (int(i) for i in input().split())
x,y,mod,m = [],[],1777777777,1
for i in range(k,1,-1):
	if i%2: x.append(m)
	else: y.append(m)
	m = (m*i)%mod
def power(n,k):
	if k==1: return n
	elif k%2==0: return power((n**2)%mod,k//2)
	else: return (n*power(n,k-1))%mod
ans = ((sum(y)-sum(x))*power(2*y[-1],mod-2))%mod
for i in range(n-k+1,n+1): ans = (ans*i)%mod
print(ans)