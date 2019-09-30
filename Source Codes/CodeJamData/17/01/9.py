import sys
import numpy as np

def solve( state, K ):
	N = len(state)
	xs = np.array( [1 if s == '+' else 0 for s in state ])

	ret = 0
	for i in range(N-K+1):
		if xs[i] == 0:
			ret += 1
			xs[i:i+K] = 1 - xs[i:i+K]
		#print i, xs

	if xs[-K:].sum() == K:
		return "%d" % ret
	return "IMPOSSIBLE"


if __name__ == "__main__":
	fd_input = open( sys.argv[1] )
	fd_output = open( sys.argv[1].replace(".in", ".out"), "w" )

	T = int( fd_input.readline().strip() )
	for t in range(T):
		line = fd_input.readline().strip().split(" ")
		sol = solve( line[0], int(line[1]) )
		fd_output.write( "Case #%d: %s\n" % (t+1, sol) )

	fd_input.close()
	fd_output.close()

