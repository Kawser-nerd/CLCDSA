from math import factorial
n,k = (int(i) for i in input().split())
if k>=n:
	a,b = k%n,n-k%n
	a = min(a,b)
	ans = factorial(n)//(factorial(a)*factorial(n-a))
	print(ans%(10**9+7))
else:
	ans = factorial((k+n)-1)//(factorial(k)*factorial(n-1))
	print(ans%(10**9+7))