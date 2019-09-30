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

def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)

N, M = LI()
S = input()
T = input()

#  N, M = 10**5, 10**5
#  S = 's'*N
#  T = 't'*M

X = lcm(N, M)
L = X
#  XS = ['X' for i in range(L+1)]
#  XT = ['X' for i in range(L+1)]
XS, XT = {}, {}
count = 0
LN = L/N
while True:
    XS[int(count*LN)] = S[count]
    count += 1
    if count > N-1:
        break

count = 0
LM = L/M
while True:
    XT[int(count*LM)] = T[count]
    count += 1
    if count > M-1:
        break

for key, value in XS.items():
    #  print(key, value)
    if key in XT:
        if value != XT[key]:
            print(-1)
            exit()
#  print(XS, XT)
#  for i in range(0, L+1):
#      if XS[i] != 'X' and XT[i] != 'X':
#          if XT[i] != XS[i]:
#              print(-1)
#              exit()
print(L)