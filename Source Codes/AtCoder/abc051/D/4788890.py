from collections import deque
from operator import itemgetter
n,m = map(int,input().split())
edge = [list(map(int,input().split())) for i in range(m)]

kyori =[[float("inf")]*n for i in range(n)]
for i in range(n):
  kyori[i][i] = 0
  
def dfs(start,goal):
  visited_cost = [float("inf")]*n
  visited_cost[start] = 0
  que = deque()
  que.append(start)
  while que:
    pos = que.pop()
    for [next_pos,cost] in tree[pos]:
      #print(next_pos,cost)
      if visited_cost[next_pos] > visited_cost[pos] + cost:
        visited_cost[next_pos] = visited_cost[pos] + cost
        que.append(next_pos)    
  return visited_cost[goal]

edge = sorted(edge, key=itemgetter(2))
tree = [[] for i in range(n)]

ans = m
for [start,goal,cost] in edge:
  start -= 1
  goal -= 1
  if cost <= dfs(start,goal):
    tree[start].append([goal,cost])
    tree[goal].append([start,cost])
    ans -= 1
    
print(ans)