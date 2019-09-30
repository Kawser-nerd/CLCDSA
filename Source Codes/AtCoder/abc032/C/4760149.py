N, K = map(int, input().split())
S = []
for _ in range(N):
	S.append( int(input()) )
if 0 in S:
	print(N)
	exit()
total = 1
r = 0
l = 0
ans = 0
while total <= K and r < N:
	total *= S[r]
	r += 1
	while total > K and l <= r:
		total //= S[l]
		l += 1
	ans = max(ans, r-l)
print(ans)