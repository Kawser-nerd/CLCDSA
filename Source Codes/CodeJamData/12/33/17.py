def opti(n, qn, m, qm):
	if (n, qn, m, qm) in dp:
		return dp[n, qn, m, qm]

	if n == N or m == M:
		return 0
	if qn == 0:
		return opti(n+1, boxes[n+1][0] if n+1 != N else None, m, qm)
	if qm == 0:
		return opti(n, qn, m+1, toys[m+1][0] if m+1 != M else None)

	if boxes[n][1] == toys[m][1]:
		dp[n, qn, m, qm] = min(qn, qm) + opti(n, qn - min(qn, qm), m, qm - min(qn, qm))
	else:
		dp[n, qn, m, qm] = max(opti(n+1, boxes[n+1][0] if n+1 != N else None, m, qm), opti(n, qn, m+1, toys[m+1][0] if m+1 != M else None))
	return dp[n, qn, m, qm]

T = int(raw_input())
for t in range(1, T+1):
	N, M = map(int, raw_input().split())
	l1 = map(int, raw_input().split())
	l2 = map(int, raw_input().split())
	boxes = []
	toys = []
	dp = {}
	for i in range(0, 2*N, 2):
		boxes.append((l1[i], l1[i+1]))
	for i in range(0, 2*M, 2):
		toys.append((l2[i], l2[i+1]))
	print "Case #{0}: {1}".format(t, opti(0, boxes[0][0], 0, toys[0][0]))
