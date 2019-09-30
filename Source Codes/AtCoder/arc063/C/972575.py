from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

def inc(x):
  if x == "No":
    return "No"
  elif x == "Any":
    return "Any"
  else:
    (a, b, p) = x
    return (a-1, b+1, (p+1)%2)

def imin(x, y):
  if x == "No" or y == "No":
    return "No"
  elif y == "Any":
    return x
  elif x == "Any":
    return y
  else:
    (a1, b1, p1) = x
    (a2, b2, p2) = y
    if p1 != p2 or b1 < a2 or b2 < a1:
      return "No"
    else:
      return (max(a1, a2), min(b1, b2), p1)

setrecursionlimit(1000000)

N = read()

edges = [[] for i in range(N)]

for i in range(N-1):
  (A, B) = reads()
  (A, B) = (A-1, B-1)
  edges[A].append(B)
  edges[B].append(A)

K = read()
d = ["Any"] * N

for i in range(K):
  (V, P) = reads()
  V = V - 1
  d[V] = (P, P, P%2)

children = [[] for i in range(N)]
parent = [0] * N

parent[0] = None
def walk(n):
  children[n] = list(edges[n])
  if n != 0:
    children[n].remove(parent[n])
  for i in children[n]:
    parent[i] = n
    walk(i)
    # print("i = {0}, d[i] = {1} ".format(i, d[i]))
  d[n] = reduce(imin, (inc(d[i]) for i in children[n]), d[n])

walk(0)

f = [0] * N
def walk2(n, k = None):
  if d[n] == "No":
    print("No"); exit()
  elif d[n] == "Any":
    f[n] = k+1
  else:
    (a, b, p) = d[n]
    if k == None:
      if a % 2 == p:
        f[n] = a
      else:
        f[n] = a + 1
    else:
      if a <= k-1 <= b:
        f[n] = k-1
      elif a <= k+1 <= b:
        f[n] = k+1
      else:
        print("No"); exit()
  for i in children[n]:
    walk2(i, f[n])

walk2(0)

print("Yes")
for i in range(N):
  print(f[i])