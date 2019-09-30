n = int(input())
c = []
not_c = []
chosen = set()
ans = 0
for i in range(n):
	a, b = map(int, input().split())
	not_c.append([max(a, b), i])
	c.append([min(a, b), i])
	ans += min(a, b)
	if a < b:
		chosen.add("a")
	elif a > b:
		chosen.add("b")

if len(chosen) < 2:
	print(ans)
else:
	c = sorted(c, reverse=True)
	not_c = sorted(not_c)
	#print(c, not_c)
	#used_c = [False] * n
	#used_n = [False] * n

	if c[0][1] != not_c[0][1]:
		ans = ans - c[0][0] + not_c[0][0]
		c_cur = 1
		not_cur = 1
	else:
		ans = min(ans - c[1][0] + not_c[0][0], ans - c[0][0] + not_c[1][0])
		if ans - c[1][0] + not_c[0][0] <= ans - c[0][0] + not_c[1][0]:
			c_cur = 2
			not_cur = 1
		else:
			c_cur = 1
			not_cur = 2
	if c_cur < n and not_cur < n:
		while c[c_cur][0] > not_c[not_cur][0]:
			if c[c_cur][1] != not_c[not_cur][1]:
				ans = ans - c[c_cur][0] + not_c[not_cur][0]
				c_cur += 1
				not_cur += 1
			else:
				ans = min(ans - c[c_cur+1][0] + not_c[not_cur][0], ans - c[c_cur][0] + not_c[not_cur+1][0])
				if ans - c[c_cur+1][0] + not_c[not_cur][0] <= ans - c[c_cur][0] + not_c[not_cur+1][0]:
					c_cur += 2
					not_cur += 1
				else:
					c_cur += 1
					not_cur += 2
			if c_cur >= n or not_cur >= n:
				break
	print(ans)