n,m = map(int, input().split())

line = [[0 for i in range(n)] for j in range(n)]


for i in range(m):
    a,b = map(int, input().split())
    line[a-1][b-1] = 1
    line[b-1][a-1] = 1

stack = [0]
visited = [[0]]
ans = 0

while stack:
    p = stack.pop()
    v = visited.pop()
    for i in range(n):
        if line[p][i]:
            if i not in v:
                if len(v) == n-1:
                    ans += 1
                else:
                    stack.append(i)
                    v.append(i)
                    visited.append([x for x in v])
                    v.pop()

print(ans)