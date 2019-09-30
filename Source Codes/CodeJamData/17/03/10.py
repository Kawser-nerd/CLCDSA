import sys
import numpy as np

def divide(S, count):
	if S%2 == 0:
		return [ (S/2-1,count), (S/2,count) ]
	return [(S/2,2*count)]


def solve( N, K ):
	segs = {N:1}

	for i in range(1000):
		if K <= 2**i:
			break
		K -= 2**i

		temp = {}
		for s in segs.items():
			for z in divide( s[0], s[1] ):
				temp[ z[0] ] = temp.get(z[0],0) + z[1]
		segs = temp

		# print i, segs

	intervals = segs.items()
	intervals.sort()
	intervals.reverse()
	#print K, intervals

	for l,cnt in intervals:
		if K <= cnt:
			max_interval = l
			break
		else:
			K -= cnt
	

	return max_interval/2, max_interval/2 - (1 if max_interval%2 == 0 else 0)


def test( N ):
	ret = []

	segs = {N:1}

	for k in range(N):
		max_l = max( segs.keys() )
		ls, rs = max_l/2, max_l/2 - (1 if max_l%2 == 0 else 0)
		
		ret.append( (ls,rs))

		segs[ max_l ] -= 1
		if segs[max_l] == 0:
			segs.pop( max_l )
		segs[ ls ] = segs.get(ls,0)+1
		segs[ rs ] = segs.get(rs,0)+1
		
	return ret

"""
for N in range(1,100):
	print N, ( test(N) == [ solve( N, k ) for k in range(1,N+1) ] )
asdf
"""

if __name__ == "__main__":
	fd_input = open( sys.argv[1] )
	fd_output = open( sys.argv[1].replace(".in", ".out"), "w" )

	T = int( fd_input.readline().strip() )
	for t in range(T):
		line = fd_input.readline().strip().split(" ")
		sol = solve( int(line[0]), int(line[1]) )
		fd_output.write( "Case #%d: %d %d\n" % (t+1, sol[0],sol[1]) )

	fd_input.close()
	fd_output.close()

