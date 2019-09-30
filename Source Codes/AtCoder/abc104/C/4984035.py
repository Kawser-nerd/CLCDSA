import math
INF = 10**10

D,G=map(int, input().split())
pc=[list(map(int, input().split())) for _ in range(D)]

def solve(i, partial, cnt, pts):
	if i == len(pc):
		if partial != -1 and pts < G:
			nokori = math.ceil((G - pts) / (100 * (1 + partial)))
			if nokori < pc[partial][0]:
				return cnt + nokori
		elif pts >= G:
			return cnt
		return INF

	ans = []
	ans.append(solve(i + 1, partial, cnt + pc[i][0], pts + 100 * (1 + i) * pc[i][0] + pc[i][1]))
	ans.append(solve(i + 1, partial, cnt, pts))

	if partial == -1:
		ans.append(solve(i + 1, i, cnt, pts))

	return min(ans)

print(solve(0, -1, 0, 0))