from sys import exit, setrecursionlimit
from itertools import product

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

def argmin(ll):
  ll = list(ll)
  return ll.index(min(ll))

setrecursionlimit(1000000)

(N, K) = reads()
parent = [x-1 for x in reads()]

result = 0
if parent[0] != 0:
  parent[0] = 0
  result += 1

children = [[] for _ in range(N)]
for i in range(1, N):
  children[parent[i]].append(i)

color = [0] * N

def walk(i):
  global result
  for x in children[i]:
    walk(x)
    if color[x] == 1 and parent[x] != 0:
      result += 1
  color[i] = min([K] + [color[x]-1 for x in children[i] if color[x] >= 2])

walk(0)

print(result)