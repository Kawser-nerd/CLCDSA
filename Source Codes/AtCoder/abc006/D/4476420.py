N = int(input())
c = [int(input()) for i in range(N)]
INF = 1000000007

# ????????????????????????
def lis(X):
	N = len(X)
	# ????
	last = [0]

	for i in range(N):
		le = 0
		gt = len(last)
		while gt - le > 1:
			mid = (le + gt) // 2
			if last[mid] <= X[i]:
				le = mid
			else:
				gt = mid
		if len(last) <= gt:
			last.append(X[i])
		else:
			last[le + 1] = X[i]
	
	return len(last) - 1
		
print(len(c) - lis(c))