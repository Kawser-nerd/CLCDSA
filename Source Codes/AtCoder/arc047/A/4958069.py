from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime,random
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N,L = inpl()
S = input()

cnt = 1
ans = 0
for s in S:
    if s == '+':
        cnt += 1
    else:
        cnt -= 1

    if cnt > L:
        ans += 1
        cnt = 1

print(ans)