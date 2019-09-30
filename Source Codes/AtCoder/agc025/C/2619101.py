from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N = read()
L = []
R = []

for _ in range(N):
  (l, r) = reads()
  L.append(l)
  R.append(-r)

L.sort(); L.reverse()
R.sort(); R.reverse()

psumL = [0] * (N+1)
psumR = [0] * (N+1)

for i in range(N):
  psumL[i+1] = psumL[i] + L[i]
  psumR[i+1] = psumR[i] + R[i]

ans = 0

for i in range(N+1):
  ans = max(ans, psumL[i] + psumR[i])

for i in range(N):
  ans = max(ans, psumL[i] + psumR[i+1])
  ans = max(ans, psumL[i+1] + psumR[i])

print(ans * 2)