# ????+1?
from collections import defaultdict
import heapq as hq

N = int(input())
P = list(map(lambda x:int(x)-1,input().split()))
D = [0]*N
for p in P:
  D[p] += 1

child_L = defaultdict(list)

S = [p for p in range(N) if D[p] == 0]
L = [None]*N

while S:
  n = S.pop()

  q = child_L[n]
  del child_L[n]

  hq.heapify(q)
  i = 0
  while q:
    t = hq.heappop(q)
    if i < t:
      break
    else:
      i += (i==t)
  
  L[n] = i
  m = P[n]
  child_L[m].append(i)
  D[m] -= 1
  if D[m] == 0:
    S.append(m)

# cycle check
try:
  start = D.index(1)
except ValueError:
  print('POSSIBLE')
  exit()

def helper(n):
  q = child_L[n]
  del child_L[n]
  
  hq.heapify(q)
  i = 0
  while q:
    t = hq.heappop(q)
    if i < t:
      break
    else:
      i += (i==t)

  j = i+1
  while q:
    t = hq.heappop(q)
    if j < t:
      break
    else:
      j += (j==t)

  return (i,j)


s1,s2 = helper(start)
G = []
n = P[start]
while n != start:
  G.append(helper(n))
  n = P[n]


del N,P,D,child_L,S,L


# ?????????????????
# 1
n = s1
for g in G:
  if g[0] == n:
    n = g[1]
  else:
    n = g[0]
if n != s1:
  print('POSSIBLE')
  exit()

# 2
n = s2
for g in G:
  if g[0] == n:
    n = g[1]
  else:
    n = g[0]
if n == s1:
  print('POSSIBLE')
  exit()

print('IMPOSSIBLE')