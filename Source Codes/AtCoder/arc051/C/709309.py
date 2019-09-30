# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

sys.setrecursionlimit(100000)

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

M = 10**9 + 7

(N, A, B) = reads()
aa = reads()
aa.sort()

if A == 1:
  for a in aa:
    print(a)
  sys.exit()

aa = [(aa[i], i) for i in range(N)]

count = B

while B > 0:
  # print(aa)
  (a, i) = aa[0]
  if i == N - 1:
    break
  aa.pop(0)
  aa.append((a*A, i))
  aa.sort()
  B -= 1

aa = [a % M for (a, i) in aa]

Q = B // N
R = B % N

aa = [(a * pow(A, Q, M)) % M for a in aa]

for _ in range(R):
  a = aa.pop(0)
  aa.append((a * A) % M)

for a in aa:
  print(a)