N, K=map(int, input().split())
A=list(sorted(list(map(int, input().split())), reverse=True))

def gcd(a,b):
	while b:
		a,b=b,a%b
	return a

g=A[0]
for i in range(1,len(A)):
	g=gcd(g,A[i])

print("POSSIBLE" if K%g==0 and K<=max(A) else "IMPOSSIBLE")