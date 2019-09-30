def mult(X, Y):
	C = [0 for i in xrange(len(X) + len(Y) - 1)]
	for i, x in enumerate(X):
		for j, y in enumerate(Y):
			C[i + j] += x * y
	return C

def sol(P, N):
	pols = []
	for x in P:
		pols.append([x, 1 - x])
	for i in xrange(1, N):
		pols[0] = mult(pols[0], pols[i])
	return pols[0][N/2]


for case in xrange(1, input() + 1):
	N, K = map(int, raw_input().split())
	P = map(float, raw_input().split())
	P.sort()
	P = P + P
	ans = 0
	for i in xrange(2 * N - K + 1):
		ans = max(ans, sol(P[i:i + K], K))
	print "Case #" + str(case) + ":",
	print "%.15f" % (ans)