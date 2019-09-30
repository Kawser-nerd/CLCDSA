#!python3

def solve(N, K):
	cnt = {N: 1}
	while cnt:
		# print(cnt)
		n = max(cnt.keys())
		if K <= cnt[n]:
			return n//2, (n-1)//2
		else:
			K -= cnt[n]
		if (n-1)//2:
			cnt[(n-1)//2] = cnt.get((n-1)//2, 0)+cnt[n]
		if n//2:
			cnt[n//2] = cnt.get(n//2, 0)+cnt[n]
		del cnt[n]

def main():
	ntest = int(input())
	for i in range(ntest):
		N, K = tuple(map(int, input().strip().split(' ')))
		ma, mi = solve(N, K)
		print("Case #%d: %d %d" % (i+1, ma, mi))
		#1000000000000000000

if __name__ == '__main__':
	main()
	# print(solve(100, 100))
	# solve(132)
	# solve(1000)
	# solve(7)
	# solve(111111110)