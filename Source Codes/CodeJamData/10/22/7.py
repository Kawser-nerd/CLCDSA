tn = int(raw_input())

def solve(a, k):
	cnt = 0
	for x in reversed(a):
		if x == 1:
			k -= 1
			if k == 0:
				break
		else:
			cnt += k
	return cnt


for loop in xrange(tn):
	print 'Case #%d:' % (loop+1), 
	N, K, B, T = [int(x) for x in raw_input().split()]
	X = [int(x) for x in raw_input().split()]
	V = [int(x) for x in raw_input().split()]
	C = []
	cnt = 0
	for i in xrange(N):
		if X[i] + V[i] * T >= B:
			cnt += 1
			C.append(1)
		else:
			C.append(0)
	if cnt >= K:
		# possible
		print solve(C, K)
	else:
		print 'IMPOSSIBLE'


