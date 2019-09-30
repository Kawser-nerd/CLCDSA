import sys

input = sys.stdin

T = int(input.readline())
for t in range(1, T + 1):
	print 'Case #{t}:'.format(t = t),
	N = int(input.readline())
	G = []
	leafs = []
	for n in range(N):
		line = input.readline().split(' ')
		if int(line[0]) == 0:
			leafs.append(n)
		G.append([int(i) - 1 for i in line[1:int(line[0]) + 1]])

	roots = set([i for i in range(N)])
	for i in range(N):
		for j in G[i]:
			if j in roots:
				roots.remove(j)

	for i in roots:
		traversed = [i]
		queue = G[i]
#		print i, traversed
		while len(queue):
			node = queue.pop()
#			print node, traversed
			if node in traversed:
				print 'Yes'
				break
			traversed.append(node)
			queue += G[node]
		else:
#			print
			continue
		break
	else:
		print 'No'
