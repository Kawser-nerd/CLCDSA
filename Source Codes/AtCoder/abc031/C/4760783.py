N = int(input())
S = list( map(int,input().split()) )
ans = -float('inf')
for n in range(N):
	T = -float('inf')
	A = -float('inf')
	for m in range(N):
		if n != m:
			a, b = min(n,m), max(n,m)
			tT = sum(S[a:b+1:2])
			tA = sum(S[a+1:b+1:2])
			if A != tA:
				T, A = max( [T,A], [tT,tA], key=lambda x:x[1] )
	ans = max(ans, T)
print(ans)