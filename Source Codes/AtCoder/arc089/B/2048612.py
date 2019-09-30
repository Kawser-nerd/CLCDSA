from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def reads():
  return [int(x) for x in input().split()]

(N, K) = reads()

L = K

board = [[0] * K for _ in range(K)]

NW = 0
for _ in range(N):
    (x, y, c) = input().split()
    (x, y) = (int(x), int(y))
    c = (x // K + y // K + int(c == "W")) & 1 # W -> 1, B -> 0
    (x, y) = (x % K, y % K)
    NW += c
    board[y][x] += 1 if c == 1 else -1 # W - B
NB = N - NW

psumr = [[0] * (K+1) for _ in range(K)]

for i in range(K):
    for j in range(K):
        psumr[i][j+1] = psumr[i][j] + board[i][j]

psum = [[0] * (K+1) for _ in range(K+1)]

for i in range(K):
    for j in range(K):
        psum[i+1][j+1] = psum[i][j+1] + psumr[i][j+1]

result = 0
for i in range(K+1):
    for j in range(K+1):
        summ = psum[i][K] + psum[K][j] - 2 * psum[i][j]
        result = max(result, NB + summ, NW - summ)
print(result)