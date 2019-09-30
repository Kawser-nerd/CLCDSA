import itertools

def solve(N, Z, F):
	p = Z.index(min(Z))
	ans = Z[p]
	S = [p]
	V = [False]*N
	V[p] = True

	for _ in range(N-1):
		next = -1
		for p in range(N):
			if V[p]:
				continue

			s = S[:]
			while len(s)>0 and not F[s[-1]][p]:
				s.pop()
			if len(s)==0:
				continue

			s += [p]
			v = V[:]
			c = [False]*N
			while len(s)>0:
				q = s.pop()
				v[q] = True
				for i in range(N):
					if F[q][i] and not v[i]:
						s += [i]
					c[q] = True

			ok = True
			for i in range(N):
				if not v[i] and not V[i]:
					ok = False

			if ok and (next<0 or Z[p]<Z[next]):
				next = p

		ans += Z[next]
		while not F[S[-1]][next]:
			S.pop()
		S += [next]
		V[next] = True

	return ans

for t in range(input()):
	N, M = map(int, raw_input().split())
	Z = [raw_input() for _ in range(N)]
	F = [[False]*N for _ in range(N)]
	for _ in range(M):
		a, b = map(lambda x: int(x)-1, raw_input().split())
		F[a][b] = F[b][a] = True
	print "Case #%s: %s" % (t+1, solve(N,Z,F))
