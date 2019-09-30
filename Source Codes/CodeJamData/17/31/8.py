import sys
sys.stdin = open('A-large.in', 'r')
sys.stdout = open('A-large.out', 'w')

pi = 3.1415926535897932384626433832

def wid(rh):
	return rh[0]*rh[0]

def ht(rh):
	return 2*rh[0]*rh[1]

for t in range(int(input())):
	n, k = map(int, input().split())
	a = [tuple(map(int, input().split())) for i in range(n)]

	a.sort(key = lambda x: x[0])

	r = 0

	side = []
	for i in range(n):
		tr = 0
		for j in range(min(i, k-1)):
			tr += side[j]

		r = max(r, tr + wid(a[i]) + ht(a[i]))

		side += [ht(a[i])]
		side.sort(key = lambda x: -x)

	print('Case #%d: %.9f' % (t+1, pi * r))
