n = int(input())
fn,fk,mod = [1]*n,[1]*n,10**9+7
for i in range(n-1): fn[i+1] = (fn[i]*(i+2))%mod
def power(n,k):
	if k==1: return n
	elif k%2==0: return power((n**2)%mod,k//2)
	else: return (n*power(n,k-1))%mod
def comb(n,k):
	if n<k or k<0: return 0
	elif k==0 or n==k: return 1
	else: return (((fn[n-1]*fk[n-k-1])%mod)*fk[k-1])%mod
fk[-1] = power(fn[-1],mod-2)
for i in range(2,n+1): fk[-i] = (fk[-i+1]*(n+2-i))%mod
fn.append(1)
ans = fn[n-2]*(n-1)
for i in range(n-2,(n-1)//2,-1):
	ans = (ans-comb(i-1,n-i-1)*fn[i-1]*fn[n-i-2])%mod
print(ans)