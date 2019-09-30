from collections import defaultdict
def main():
	N, M = map(int, input().split())
	A = list(map(int, input().split()))
	sums = [0]*(N+1)
	ans = 0
	mod = defaultdict(int)
	mod[0] = 1
	for i in range(1, N+1):
		sums[i] = (sums[i-1] + A[i-1]) % M
		ans += mod[sums[i]]
		mod[sums[i]] += 1

	print(ans)

if __name__ == '__main__':
    main()