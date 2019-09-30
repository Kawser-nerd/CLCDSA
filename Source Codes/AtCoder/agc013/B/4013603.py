from collections import deque
n, m = map(int, input().split())
edges = [[] for _ in range(n+1)]
for _ in range(m):
	a, b = map(int, input().split())
	edges[a].append(b)
	edges[b].append(a)
ans = deque([1, edges[1][0]])
used = [False] * (n+1)
used[1], used[edges[1][0]] = True, True
#print(ans)
while True:
	ok = True
	for e in edges[ans[0]]:
		if used[e] == False:
			ans.appendleft(e)
			used[e] = True
			ok = False
			break
	for e in edges[ans[-1]]:
		#print(e)
		if used[e] == False:
			ans.append(e)
			used[e] = True
			ok = False
			break

	if ok:
		break

print(len(ans))
print(*ans)