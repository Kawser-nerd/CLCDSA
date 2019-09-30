m,n,N = map(int,input().split())
res = N
while N >= m:
	x = N//m
	res += x*n
	k = N -m*x
	N = x*n+k
print(res)