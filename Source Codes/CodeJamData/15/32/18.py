def go(left, pos):
	if pos == m:
		t = 0
		for i in range(m):
			if s[:i] == s[pos - i:pos]:
				t = i
		pos = t

	if left == 0:
		return 0

	if dp[left][pos] != -1:
		return dp[left][pos]
	res = 0

	for i in range(k):
		c = ord(let[i]) - ord('A')
		npos = jump[pos][c]
		cur = 0.0
		if npos == m:
			cur = 1.0
		cur = (go(left - 1, npos) + cur) / k
		res += cur

	dp[left][pos] = res
	return res	

def solve(test):
	global k, m, n, let, s, dp, jump
	k, m, n = map(int, input().split())
	let = input()
	s = input()

	dp = [[-1 for i in range(105)] for i in range(105)]
	jump = [[0 for i in range(26)] for i in range(105)]


	for i in range(m):
		for c in range(26):
			if ord(s[i]) - ord('A') == c:
				jump[i][c] = i + 1
				continue

			for j in range(i):
				if s[:j] == s[i - j:i] and ord(s[j]) - ord('A') == c:
					jump[i][c] = j + 1

	ans = 0
	mx = 0
	for i in range(1, m):
		if s[0:i] == s[m - i:m]:
			mx = i

	ans = 1 + (n - m) // (m - mx)

	for i in range(m):
		ok = 0
		for j in range(k):
			if s[i] == let[j]:
				ok = 1
		if ok == 0:
			ans = 0

	print('Case #%d: %.8f' % (test, ans - go(n, 0)))

t = int(input())
for i in range(t):
 	solve(i + 1);
