from heapq import *
for case in xrange(1, input() + 1):
	N, S = map(int, raw_input().split())
	pos = []
	vel = []
	for _ in xrange(N):
		a, b, c, d, e, f = map(int, raw_input().split())
		pos.append((a, b, c))
		vel.append((d, e, f))
	G = [[] for i in xrange(N)]
	V = [0 for i in xrange(N)]
	for i in xrange(N):
		for j in xrange(i + 1, N):
			G[i].append([(pos[i][0] - pos[j][0]) ** 2 + (pos[i][1] - pos[j][1]) ** 2 + (pos[i][2] - pos[j][2]) ** 2, j])
			G[j].append([(pos[i][0] - pos[j][0]) ** 2 + (pos[i][1] - pos[j][1]) ** 2 + (pos[i][2] - pos[j][2]) ** 2, i])
	q = []
	for x in G[0]:
		heappush(q, x)
	V[0] = 1
	while True:
		a, b = heappop(q)
		if V[b]: continue
		V[b] = 1
		if b == 1:
			ans = a
			break
		for x in G[b]:
			heappush(q, [max(a, x[0]), x[1]])
	print "Case #" + str(case) + ":",
	print "%.10f" % (ans ** 0.5)
