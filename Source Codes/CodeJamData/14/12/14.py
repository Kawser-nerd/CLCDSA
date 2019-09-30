import sys
from collections import deque

f = open(sys.argv[1])
for t in range(1, int(f.readline())+1):
	N = int(f.readline())
	G = {}
	
	def is_connected(in_tree):
		num_edges = 0
		for i in in_tree:
			s = G[i]
			for j in s:
				if j in in_tree:
					num_edges += 1
		if num_edges / 2 == len(in_tree) - 1:
			return 1
		else:
			return 0
	
	def is_tree(in_tree, root):
		if len(in_tree) == 0 and root != -1:
			return 1
		if len(in_tree) == 1:
			return 1
		elif len(in_tree) == 2 and root == -1:
			return 0
	

		#
		# Make sure that all degrees are either 1, 2 or 3.
		# Find all vertices with degree 1 and remove them.
		#
		
		leaves = set()
		dcount = 0
		for i in in_tree:
			neighbors = G[i]
			ncount = 0
			for j in neighbors:
			 	if j in in_tree:
			 		ncount += 1
	 		if ncount not in [1, 2, 3]:
	 			return 0
 			if ncount == 1:
 				leaves.add(i)	
			if ncount == 2:
				dcount += 1
				rootcan = i
		
		if dcount != 1 and root == -1:
			return 0
		
		if root != -1:	
			rootcan = root
		return is_tree(in_tree.difference(leaves), rootcan)		
	
	for i in range(N-1):
		src, dst = map(int, f.readline().split())
		src -= 1
		dst -= 1
		if src in G:
			G[src].append(dst)
		else:
			G[src] = [dst]
			
		if dst in G:
			G[dst].append(src)
		else:
			G[dst] = [src]

	min_dels = N-1;	
	for combo in range(1, 2**N):
		in_tree = set()
		se = combo
		for i in range(N):
			if se & 1:
				in_tree.add(i)
			se = se >> 1
		
		if is_tree(in_tree, -1) and is_connected(in_tree):
			dels = N - len(in_tree)
			if dels < min_dels:
				min_dels = dels
		
	print 'Case #%d: %d' % (t, min_dels)
