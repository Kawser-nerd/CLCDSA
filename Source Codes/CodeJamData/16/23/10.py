# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

T = read()

for case in range(1, T+1):
  N = read()
  G = dict()
  V = set()

  for _ in range(N):
    (S, T) = input().split()
    V.add((S, 0)); V.add((T, 1))
    if not (S, 0) in G:
      G[(S, 0)] = []
    G[(S, 0)].append((T, 1))
    if not (T, 1) in G:
      G[(T, 1)] = []
    G[(T, 1)].append((S, 0))

  res = 0
  match = {v : -1 for v in V}

  def dfs(v, used):
    used[v] = True
    for u in G[v]:
      w = match[u]
      if (w == -1) or (not used[w]) and dfs(w, used):
        match[v] = u
        match[u] = v
        return True
    return False

  for v in V:
    if match[v] == -1:
      used = {v : 0 for v in V}
      if dfs(v, used):
        res += 1

  result = N - (res + sum(match[v] == -1 for v in V))

  print("Case #{0}: {1}".format(case, result))
