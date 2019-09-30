import sys
import numpy as np


def solve( s ):
	last_safe = 0
	violated = False
	for i in range(1, len(s)):
		if s[i-1] < s[i]:
			last_safe = i
		elif s[i-1] > s[i]:
			violated = True
			break

	if violated == False:
		return s

	ret = [ int(s[i]) if i < last_safe else int(s[i])-1 if i == last_safe else 9 for i in range(len(s)) ]

	while ret[0] == 0:
		ret = ret[1:]

	return "".join( "%d" % r for r in ret )

def validate( num ):
	r = str(num)
	return all( r[i-1] <= r[i] for i in range(1,len(r)) )

def test( s, r ):
	print s, r
	assert( r <= s )
	assert( validate(r) )

	for x in range(s,0,-1):
		if validate(x):
			print s, r, x
			assert( x == r )
			return

	assert( False )


if __name__ == "__main__":
	fd_input = open( sys.argv[1] )
	fd_output = open( sys.argv[1].replace(".in", ".out"), "w" )

	T = int( fd_input.readline().strip() )
	for t in range(T):
		line = fd_input.readline().strip()
		sol = solve( line )
		#test( int(line), int(sol) )
		fd_output.write( "Case #%d: %s\n" % (t+1, sol) )

	fd_input.close()
	fd_output.close()

