import sys
sys.setrecursionlimit(1000000)
n, m = map(int, input().split())
s = input()
links = [[] for _ in range(2*n)]
visit = [0] * n *2
for line in sys.stdin.readlines():
    a, b = map(int, line.split())
    a -= 1
    b -= 1
    if s[a] == s[b]:
      links[a].append(b+n)
      links[b].append(a+n)
    else:
      links[a+n].append(b)
      links[b+n].append(a)
def dfs(v):
  visit[v] = 1
  for i in links[v]:
    if visit[i] == 1:
      print("Yes")
      exit()
    elif visit[i] == 0:
      dfs(i)
  visit[v] = -1
  
for i in range(n):
  if visit[i] == 0:
    dfs(i)
print("No")