cases = input()

for cas in range(1, cases + 1):
	n = input()
	a = map(int, raw_input().split(' '))
	print 'Case #%d:' % cas, 
	l = []
	r = []
	for i in range(n):
		l.append(0)
		r.append(0)
	for i in range(n):
		for j in range(i + 1):
			if a[j] > a[i] : l[i] += 1
		for j in range(i, n):
			if a[i] < a[j] : r[i] += 1
	res = 0
	for i in range(n):
		res += min(l[i], r[i])
	print res
