tn = int(raw_input())

def update(l, d):
	if not l:
		return 0
	cnt = 0
	if l[0] not in d:
		d[l[0]] = {}
		cnt = 1
	return cnt + update(l[1:], d[l[0]])

for loop in xrange(tn):
	print 'Case #%d:' % (loop+1), 
	N, M = [int(x) for x in raw_input().split()]
	cnt = 0
	d = {}
	for i in xrange(N):
		update(raw_input().split('/')[1:], d)
	for i in xrange(M):
		cnt += update(raw_input().split('/')[1:], d)
	print cnt
