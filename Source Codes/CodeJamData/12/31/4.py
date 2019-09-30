#

from collections import deque

T = int( raw_input() )

for t in xrange( 1, T+1 ):
	
	N = int( raw_input() )
	nodes = [None]*N
	for i in xrange(N):
		nodes[i] = map( lambda w: int(w)-1, raw_input().split()[1:] )
	
	nottree = False
	for i in xrange(N):
		
		q = deque()
		q.append( i )
		seen = set()
		
		while q:
			n = q.pop()
			if n in seen:
				nottree = True
				break
			seen.add(n)
			for m in nodes[n]:
				q.append(m)
		
		if nottree: break
	#
	
	print "Case #%d: %s" %(t, "Yes" if nottree else "No")

