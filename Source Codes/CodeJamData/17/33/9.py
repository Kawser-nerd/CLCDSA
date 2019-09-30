import sys
sys.stdin = open('C-small-1-attempt0.in', 'r')
sys.stdout = open('C-small-1-attempt0.out', 'w')

for tc in range(int(input())):
	n, k = map(int, input().split())
	u = float(input())
	a = list(map(float, input().split()))

	a.sort()
	a.append(1)

	for i in range(n):
		mx = (i+1) * (a[i+1] - a[i])
		tar = 0
		if u < mx:
			tar = a[i] + u / (i+1)
			for j in range(i+1):
				a[j] = tar
			break
		else:
			tar = a[i+1]
			for j in range(i+1):
				a[j] = tar
			u = max(u-mx, 0)


	r = 1
	for i in a:
		r *= i

	print('Case #%d: %.7f' % (tc+1, r))