import sys
import numpy as np

def solve_rowcol( init ):
	N = init.shape[0]
	
	sol = np.array( init )
	row_occpd = init.sum(axis=1)
	col_occpd = init.sum(axis=0)

	for r in range(N):
		for c in range(N):
			if row_occpd[r] == 0 and col_occpd[c] == 0:
				sol[r][c] = row_occpd[r] = col_occpd[c] = 1

	return sol

def matching( M, edges ):
	left_matched = -np.ones(M, dtype=np.int)
	right_matched = -np.ones(M, dtype=np.int)

	# initial match
	for u in range(M):
		for v in edges[u]:
			if right_matched[v] == -1:
				left_matched[u] = v
				right_matched[v] = u
				break

	while True:
		# find a augement path via BFS
		left_paths = -np.ones(M, dtype=np.int)
		right_paths = -np.ones(M, dtype=np.int)

		# aggregate unmatched
		lefts = set()
		for u in range(M):
			if left_matched[u] == -1:
				lefts.add( u )
				left_paths[u] = u

		# BFS
		goal = None

		while len(lefts) > 0:
			rights = set()
			for u in lefts:
				for v in edges[u]:
					if right_matched[v] == -1:		# unmatched
						right_paths[v] = u
						goal = v
					elif right_paths[v] == -1:		# unvisited
						right_paths[v] = u
						rights.add(v)

			if goal is not None:
				break

			lefts = set()
			for v in rights:
				u = right_matched[v]
				if left_paths[u] == -1:
					left_paths[u] = v
					lefts.add(u)

		if goal is None:
			break

		# alternate paths
		apath = [ goal, right_paths[goal] ]
		while left_matched[ apath[-1] ] != -1:
			apath.append( left_paths[ apath[-1] ] )
			apath.append( right_paths[ apath[-1] ] )
		apath.reverse()

		#print "aug_path : ", apath

		for i in range( 0, len(apath), 2 ):
			left_matched[ apath[i] ] = apath[i+1]
			right_matched[ apath[i+1] ] = apath[i]

	return [ (u, left_matched[u]) for u in range(M) if left_matched[u] != -1 ]




def solve_diag( init ):
	N = init.shape[0]
	M = 2*N-1
	
	left_occpd = np.zeros(M)
	right_occpd = np.zeros(M)

	for r in range(N):
		for c in range(N):
			if init[r][c] == 1:
				left_occpd[r+c] = right_occpd[r-c+N-1] = 1

	edges = [ [] for _ in range(M) ]
	for r in range(N):
		for c in range(N):
			u, v = r+c, r-c+N-1
			if left_occpd[u] == 0 and right_occpd[v] == 0:
				edges[u].append( v )


	optimal_matchings = matching( M, edges )

	sol = np.array( init )
	for r in range(N):
		for c in range(N):
			u, v = r+c, r-c+N-1
			if (u,v) in optimal_matchings:
				sol[r][c] = 1

	print sol.sum(), 2*N-2

	return sol


def solve( N, preplaced = [] ):
	init_rowcol = np.zeros( (N,N), dtype=np.int )
	init_diag = np.zeros( (N,N), dtype=np.int )

	for p in preplaced:
		t,r,c = p[0], p[1]-1, p[2]-1
		if t == 'o' or t == 'x':
			init_rowcol[r][c] = 1
		if t == 'o' or t == '+':
			init_diag[r][c] = 1

	sol_rowcol 	= solve_rowcol( init_rowcol )
	sol_diag 	= solve_diag( init_diag )
	tot_sol		= sol_rowcol + sol_diag

	"""
	if N > 1:
		if sol_rowcol.sum() != N or sol_diag.sum() != 2*N-2:
			print "wrong"
			print N, sol_rowcol.sum(), sol_diag.sum()
			#print "\n".join( [ "".join([ "%d" % t for t in row ] ) for row in init_diag ] )
			#print "="*128
			print "\n".join( [ "".join([ "%d" % t for t in row ] ) for row in sol_diag ] )
			raw_input()
	"""
	
	# compare with initial state
	updated = []
	for r in range(N):
		for c in range(N):
			if tot_sol[r][c] > init_rowcol[r][c] + init_diag[r][c]:
				t = 'o' if tot_sol[r][c] == 2 else '+' if sol_diag[r][c] == 1 else 'x'
				updated.append( (t, r+1,c+1) )

	return tot_sol.sum(), updated





"""
N = 3
print solve( N )
asdf

#score, sol = backtrack( [['.']*N for _ in range(N)], 0,0 )
#print score, sol
#print_sol(sol)

asdf
"""



if __name__ == "__main__":
	fd_input = open( sys.argv[1] )
	fd_output = open( sys.argv[1].replace(".in", ".out"), "w" )

	T = int( fd_input.readline().strip() )
	for t in range(T):
		line = fd_input.readline().strip().split(" ")
		N, M = int(line[0]), int(line[1])
		
		preplaced = []
		for i in range(M):
			line = fd_input.readline().strip().split(" ")
			preplaced.append( (line[0], int(line[1]), int(line[2])) )

		score, updated = solve( N, preplaced )

		fd_output.write( "Case #%d: %d %d\n" % (t+1, score, len(updated)) )
		for u in updated:
			fd_output.write( "%c %d %d\n" % u )

	fd_input.close()
	fd_output.close()

