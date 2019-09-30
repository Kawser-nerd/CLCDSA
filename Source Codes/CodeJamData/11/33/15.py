class streamreader:
	def __init__(_,s): _.t=(t for t in s.read().split())
	def __div__(_,t): return (t)(_.t.next())

import sys
sr = streamreader(sys.stdin)

for tc in xrange(sr/int):
	n, l, h = sr/int, sr/int, sr/int	
	fr = [sr/int for i in xrange(n)]

	answer = 'NO'	
	for x in xrange(l, h + 1):
		ok = True
		for f in fr:
			if f % x != 0 and x % f != 0:
				ok = False
				break
		if ok:
			answer = x
			break
	
	print 'Case #%d:' % (tc + 1), answer