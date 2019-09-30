def GetAns(Source, Curr, B):
	if sum(Curr) - sum(Source) > B:
		return 0
	ans = - sum(Curr) +  sum(Source)
	m = min(Curr)
	c = Curr.count(m)
	for i in range(len(Curr)):
		if Curr[i] == m:
			ans += (Curr[i] - Source[i]) * 36 / c
	return ans

def solve(num):
	B, N  = map(int, input().split())
	CurrB = B
	Source = list(map(int, input().split()))
	Source = Source + [0] * (37 - len(Source))
	Source.sort()
	Curr = Source[:]
	Ans = 0
	while CurrB > 0:
		Curr[0] += 1
		Curr.sort()
		CurrB -= 1
		Ans = max(Ans, GetAns(Source, Curr, B))
	print("Case #", num, ": ", Ans, sep='')

T = int(input())
for num in range(1, T + 1):
    solve(num)

