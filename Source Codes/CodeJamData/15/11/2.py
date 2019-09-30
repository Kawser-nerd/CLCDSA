def gao1(l):
	ans = 0
	for i in range(1, len(l)):
		if l[i] < l[i-1]:
			ans += l[i-1] - l[i]
	return ans

def gao2(l):
	rate = 0
	for i in range(1, len(l)):
		rate = max(rate, l[i-1] - l[i])
	ans = 0
	for i in range(1, len(l)):
		ans += min(l[i-1], rate)
	return ans
t = int(input())
for cas in range(t):
	print('Case #%d:' % (cas+1), end=' ')
	n = input()
	l = list(map(int, input().split()))
	print(gao1(l), gao2(l))

