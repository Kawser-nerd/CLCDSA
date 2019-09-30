import sys
sys.setrecursionlimit(10000)
data = [line.split() for line in sys.stdin.readlines()]
tn = int(data[0][0])
ln = 1
for ti in xrange(tn):
	n = int(data[ln][0])
	graph = [[] for i in xrange(n)]
	for i in xrange(n-1):
		a = int(data[ln+1+i][0])-1
		b = int(data[ln+1+i][1])-1
		graph[a].append(b)
		graph[b].append(a)
	dpt = {}
	# ret: numnodes, mindel
	def dp(s, f):
		global dpt
		if not (s, f) in dpt:
			childsc = []
			for b in graph[s]:
				if b != f:
					childsc.append(dp(b, s))
			numn = 1
			for sc in childsc:
				numn += sc[0]
			chn = len(childsc)
			if chn == 0:
				dpt[(s, f)] = (numn, 0)
			elif chn == 1:
				dpt[(s, f)] = (numn, childsc[0][0])
			else:
				gain = sorted([sc[1] - sc[0] for sc in childsc])
				dpt[(s, f)] = (numn, numn - 1 + gain[0] + gain[1])			
		return dpt[(s, f)]
	ln += n
	best = 10000
	for i in xrange(n):
		sc = dp(i, None)[1]
		if sc < best:
			best = sc
	print "Case #%d: %d" % (ti+1, best)
