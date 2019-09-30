def cal(m, t):
	return sum([(t+x-1)//x for x in m])

def gao():
	(b, n) = list(map(int, input().split()))
	m = list(map(int, input().split()))
	l = 0
	r = min(m) * n
	ans = r
	while l <= r:
		mid = (l + r) // 2
		s = cal(m, mid)
		if s >= n:
			ans = mid
			r = mid - 1
		else:
			l = mid + 1
	ans = ans - 1
	cnt = n - cal(m, ans)
	for i in range(len(m)):
		if ans % m[i] == 0:
			cnt -= 1
			if cnt == 0:
				return i + 1
	return -1
t = int(input())
for cas in range(t):
	print('Case #%d:' % (cas+1), end=' ')
	print(gao())

