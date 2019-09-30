class streamreader:
	def __init__(_,s): _.t=(t for t in s.read().split())
	def __div__(_,t): return (t)(_.t.next())

import sys
sr = streamreader(sys.stdin)

for tc in xrange(sr/int):
	L, t, N, C = sr/int, sr/int, sr/int, sr/int
	a = [sr/int for i in xrange(C)]
	
	A = [a[i % C] for i in xrange(N)]
	
	time = 0
	for i in xrange(N):
		if time <= t and time + A[i] * 2 > t:
			f = (t - time) / 2
			s = A[i] - f
			A[i] = f
			A.insert(i + 1, s)
			i += 1
			break
		time += A[i] * 2
		
	A0 = A[:i]
	B = A[i:]
	B.sort()
	if L == 0:
		B1 = B
		B2 = []
	else:
		B1 = B[:-L]
		B2 = B[-L:]
	
	time = 0
	for i in A0 + B1:
		time += i * 2
	
	for i in B2:
		time += i

	print 'Case #%d:' % (tc + 1), time