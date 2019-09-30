#

T = int( raw_input() )

for t in xrange( 1, T+1 ):
	
	N, M = map( int, raw_input().split() )
	one = map( int, raw_input().split() )
	two = map( int, raw_input().split() )
	
	a = one[::2]
	A = one[1::2]
	b = two[::2]
	B = two[1::2]
	
	d = {}
	def f( i, j, dx, dy ):
		if i == N or j == M: return 0
		if (i,j,dx,dy) in d: return d[(i,j,dx,dy)]
		
		if A[i] != B[j]: answer = max( f(i+1,j,0,dy), f(i,j+1,dx,0) )
		else:
			if a[i]-dx == b[j]-dy:
				answer = f(i+1,j+1,0,0) + a[i]-dx
			elif a[i]-dx < b[j]-dy:
				answer = f(i+1,j,0,dy+a[i]-dx) + a[i]-dx
			else:
				answer = f(i,j+1,dx+b[j]-dy,0) + b[j]-dy
		
		d[(i,j,dx,dy)] = answer
		return answer
	
	print "Case #%d: %d" %(t, f(0,0,0,0))

