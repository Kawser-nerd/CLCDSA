S = list(map(int, list(input())))
n = len(S)

if len(set(S)) == 1:
	print(len(S))
else:
	ans = 1000000
	for i in range(n-1):
		if S[i] != S[i+1]:
			m = max(n - i - 1, i + 1)
			if m < ans:
				ans = m

	print(ans)