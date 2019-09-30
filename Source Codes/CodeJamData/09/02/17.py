import sys

def flowingCell(map, r, c):
	if r < 0 or r >= len(map) or c < 0 or c >= len(map[0]):
		return None
	
	heights = neighborHeight(map, r, c)
	idx = heights.index( min([item for item in heights if item is not None]) )
	if idx == 0:		return (r-1, c)
	elif idx == 1:	return (r, c-1)
	elif idx == 2:	return (r, c+1)
	else:						return (r+1, c)
	
	
def neighborHeight(map, r, c):		# order : N W E S
	ret = []
	if r != 0:		ret.append( map[r-1][c] )
	else:					ret.append( None )
	
	if c != 0:		ret.append( map[r][c-1] )
	else:					ret.append( None )
	
	if c < len(map[0])-1:	ret.append( map[r][c+1] )
	else:									ret.append( None )
	
	if r < len(map)-1:			ret.append( map[r+1][c] )
	else:									ret.append( None )
	
	return ret


def solve(map):
	H = len(map)
	W = len(map[0])
	
	if H == 1 and W == 1:
		return [["a"]]
	
	solution = [ [None]*W for i in range(H) ]
	
	next = []
	
	cnt = 0
	for r in range(H):
		for c in range(W):
			fr, fc = flowingCell(map, r, c)
			if map[fr][fc] >= map[r][c]:	# (r,c) is sink
				solution[r][c] = cnt
				cnt += 1
				next.append( (r,c) )
	
	while len(next) > 0:
		last = next
		next = []
		for src in last:
			r,c = src[0], src[1]
			for dest in [ (r-1,c), (r,c-1), (r,c+1), (r+1,c) ]:
				if flowingCell(map, dest[0], dest[1]) == (r,c) and solution[dest[0]][dest[1]] is None:
					solution[dest[0]][dest[1]] = solution[r][c]
					next.append( dest )
					
	cur = ord("a")
	reidx_dic = {}
	for r in range(H):
		for c in range(W):
			if reidx_dic.has_key(solution[r][c]) == False:
				reidx_dic[ solution[r][c] ] = chr( cur )
				solution[r][c] = chr(cur)
				cur += 1
			else:
				solution[r][c] = reidx_dic[ solution[r][c] ]
	
	return solution

if __name__ == "__main__":
	infile = open( sys.argv[1], "r" )
	outfile = open( "resultB.txt", "w" )
	
	N = int( infile.readline().strip() )
	
	for case in range(N):
		line = [ int(item) for item in infile.readline().strip().split(" ")		if item != "" ]
		H, W = line[0], line[1]
		map = []
		for r in range(H):
			map.append( [ int(item) for item in infile.readline().strip().split(" ")	if item != "" ] )
	
		solution = solve(map)
	
		outfile.write( "Case #%d:\n" % (case+1) )
		outfile.write( "\n".join( [" ".join(sol) for sol in solution ] ) )
		outfile.write( "\n" )
	
	infile.close()
	outfile.close()
	