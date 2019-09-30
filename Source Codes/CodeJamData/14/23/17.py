from itertools import permutations

for tc in range(int(input())):
	N, M = (int(x) for x in input().split())
	code = [int(input()) for x in range(N)]
	G = [[False]*(N+1) for i in range(N+1)]
	for i in range(M):
		u, v = (int(x)-1 for x in input().split())
		G[u][v] = G[v][u] = True

	best = pow(10, 5*N)
	for perm in permutations(list(range(N))):
		stack = [N]
		G[N][perm[0]] = True
		valid = True
		cur = 0
		for city in perm:
			cur = cur * 100000 + code[city]
			while stack and not G[stack[-1]][city]:
				stack.pop()
			if not stack:
				valid = False
				break
			stack.append(city)
		if valid:
			best = min(best, cur)
		G[N][perm[0]] = False

	print('Case #{}: {}'.format(tc+1, best))