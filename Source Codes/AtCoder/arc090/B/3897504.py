import sys

n, m = map(int, input().split())
ed = [[] for _ in range(n)]
v = [None] * n
for _ in range(m):
	l, r, d = map(int, input().split())
	ed[l-1].append([r-1, d])
	ed[r-1].append([l-1, -d])

visited = [False] * n

def dfs(start):
	global ed, v, visited
	s = [start]
	v[start] = 0
	while s:
		label = s.pop()
		if visited[label] == False:
			visited[label] = True
			for e in ed[label]:
				if v[e[0]] is None:
					v[e[0]] = v[label] + e[1]
					s.append(e[0])
				else:
					if v[e[0]] != v[label] + e[1]:
						print("No")
						sys.exit()
	return

for i in range(n):
	if v[i] is None:
		dfs(i)

print("Yes")