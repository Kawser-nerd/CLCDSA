import collections
n,m = map(int,input().split())
s = list(input())
g = [[] for i in range(0,n)]
ab = [{"A":0,"B":0}for _ in range(0,n)]
for i in range(0,m):
    A,B = map(int,input().split())
    g[A-1].append(B-1)
    g[B-1].append(A-1)
    ab[A-1][s[B-1]] += 1
    ab[B-1][s[A-1]] += 1

visit = [0 for i in range(0,n)]
que = collections.deque()
for i in range(0,n):
    if ab[i]["A"] == 0 or ab[i]["B"] == 0:
        que.append(i)
        visit[i] = 1

while len(que) > 0:
    q = que.popleft()
    for j in g[q]:
        ab[j][s[q]] -= 1
        if (ab[j]["A"] == 0 or ab[j]["B"] == 0)and visit[j] == 0:
            que.append(j)
            visit[j] = 1
if sum(visit) == n:
    print("No")
else:
    print("Yes")