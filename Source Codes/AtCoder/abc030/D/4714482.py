n, a = map(int, input().split())
a -= 1
k = int(input())
b = list(map(int, input().split()))
for i in range(n):
    b[i] -= 1
visit = []
used = [False for _ in range(n)]

def dfs(now):
    if used[now]:
        return now
    used[now] = True
    visit.append(now)
    return dfs(b[now])
    
s = dfs(a)
d = visit.index(s)
l = len(visit) - d
r = (k - d) % l
print(visit[k]+1 if k < d else visit[d+r]+1)