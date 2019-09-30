def power(n,k):
	if k==1: return n
	elif k%2==0: return power((n**2)%mod,k//2)
	else: return (n*power(n,k-1))%mod
a = int(input())
b = int(input())
c = int(input())
mod = 10**9+7
x,y,z = (b*c-a*b)%mod,(b*c-c*a)%mod,(a*b-b*c+c*a)%mod
print((y*power(z,mod-2))%mod,(x*power(z,mod-2))%mod)