def main():
	N, X = map(int, input().split())
	x = list(map(int, input().split()))
	x.append(X)
	x.sort()
	diff = [0]*N
	for i in range(N):
		diff[i] = x[i+1] - x[i]

	def gcd(a, b):
		if (b == 0):
			return a
		else:
			return gcd(b, a%b)
	ans = diff[0]
	for c in diff[1:]:
		ans = gcd(ans, c)

	print(ans)


if __name__ == '__main__':
    main()