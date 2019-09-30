import psyco
import random
def solve(n,m,A):
	changed = 0
	if n < m:
		n,m = m,n
		changed = 1
	for t in xrange(n):
		AT = A+t
		for i in xrange(1,n+1):
			if AT%i == 0 and AT/i <= m:
				if t:
					if changed:
						print 0, 0, 1, i,AT/i,t
					else:
						print 0, 0, i,1,t,AT/i
				else:
					if changed:
						print 0,0, 0, i, A/i, 0
					else:
						print 0, 0, i,0,0,A/i
				return 1
	return 0
	
	
	
def solve2(n,m,A):
			for y1 in xrange(0, m+1):
					x1 = 0
					for x2 in xrange(x1, n+1):
						for y2 in xrange(0, m+1):
							for x3 in xrange(x2, n+1):
								for y3 in xrange(0, m+1):
									if abs(x1*y2+x2*y3+x3*y1 - x1*y3 - x2*y1 - x3*y2) == A:
										print x1, y1,x2,y2,x3,y3
										return 1
			for x1 in xrange(0, n+1):
					y1 = 0
					for x2 in xrange(x1, n+1):
						for y2 in xrange(0, m+1):
							for x3 in xrange(x2, n+1):
								for y3 in xrange(0, m+1):
									if abs(x1*y2+x2*y3+x3*y1 - x1*y3 - x2*y1 - x3*y2) == A:
										print x1, y1,x2,y2,x3,y3
										return 1
			return 0

psyco.full()

tn = input()
for loop in xrange(tn):
	print "Case #%d:" % (loop+1),
	n,m,A = [int(x) for x in raw_input().split()]

	if A>n*m:
		print "IMPOSSIBLE"
	else:
		s = solve(n,m,A)
		if not s:
			print "IMPOSSIBLE"

