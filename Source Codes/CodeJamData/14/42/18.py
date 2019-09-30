T = int(raw_input())
for tt in range(T):
	result = 0
	ll = int(raw_input())
	A = map(int, raw_input().split(" "))
	while len(A)>0:
		val, idx = min((val, idx) for (idx, val) in enumerate(A))
		result += min(idx, len(A)-idx-1)
		A = A[:idx]+A[idx+1:]
	print "Case #{0}: {1}".format(str(tt+1), str(result))
