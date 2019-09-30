def _get_perms(s):
	if len(s) == 1:
		return [list(s)]
	result = []
	for i in s:
		for j in _get_perms(s - {i}):
			result += [[i] + j]
	return result

def get_perms(n):
	return _get_perms(set(range(1, n+1)))

def possible(path, edge):
	stk = [path[0]]
	for node in path[1:]:
		while len(stk) and (stk[-1], node) not in edge:
			stk.pop()
		if len(stk) == 0:
			return False
		stk.append(node)
	return True

def do():
	nnodes, nedges = map(int, raw_input().split())
	labels = [raw_input() for x in xrange(nnodes)]
	edge = set([])
	for x in xrange(nedges):
		a, b = map(int, raw_input().split())
		edge.add((a,b))
		edge.add((b,a))
	best = '9' * (6*nnodes)
	for path in get_perms(nnodes):
		if possible(path, edge):
			s = ''.join(labels[node-1] for node in path)
			#print s
			if int(s) < int(best):
				best = s
	return best

T = input()
for i in xrange(1, T+1):
	print "Case #%s: %s" % (i, do())


		


