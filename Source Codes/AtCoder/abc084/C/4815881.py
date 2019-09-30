import math, string, itertools, fractions, heapq, collections, re,  array, bisect, sys, random, time, copy, functools
sys.setrecursionlimit(10**7)
inf = 10 ** 20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def pf(s): return print(s, flush=True)


N = I()
CSF = []
for i in range(1, N):
    CSF.append(LI())

for i in range(N-1):
    # i?????????
    current = i
    time = 0
    for csf in CSF[i:]:
        if time < csf[1]:
            # time????????????????
            time = csf[1] + csf[0]
        elif time % csf[2] == 0:
            time += csf[0]
        else:
            # time???????????????????????
            div = time % csf[2]
            time -= div
            time += csf[2]
            time += csf[0]
        current += 1
    print(time)

print(0)