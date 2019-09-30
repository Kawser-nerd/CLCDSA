from collections import Counter
n = int(input())
a = [int(i) for i in input().split()]
def power(n,k):
	if k==0: return 1
	elif k==1: return n
	elif k%2==0: return power((n**2)%mod,k//2)
	else: return (n*power(n,k-1))%mod
if a[0]!=0 or a.count(0)!=1: print(0)
else:
	c,ans,num,mod = Counter(a),1,1,10**9+7
	for i in range(1,max(a)+1):
		if c[i]==0:
			ans = 0
			break
		else:
			ans = (ans*power((power(2,num)-1),c[i])*power(2,c[i]*(c[i]-1)//2))%mod
			num = c[i]
	print(ans)