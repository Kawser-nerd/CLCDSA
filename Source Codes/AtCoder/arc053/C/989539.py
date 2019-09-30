N = int(input())
EisNegative = []
EisPositive = []
for i in range(N):
	a, b = map(int, input().split())
	e = a - b
	if e <= 0:
		EisNegative.append((a,e))
	else:
		EisPositive.append((a,e))
EisNegative.sort(key=lambda aande: aande[0])
EisPositive.sort(key=lambda aande: aande[0] - aande[1] )
EisPositive.reverse()
T = 0
ans = 0
for a, e in EisNegative:
	ans = max(a+T,ans)
	T += e
for a, e in EisPositive:
	ans = max(a+T,ans)
	T += e
print(ans)