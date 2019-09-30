from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

def func(N):
    return sum(map(int,list(str(N))))

N = int(input())
L = len(str(N))
MIN = max(N-9*L,1)

ans = []
for n in range(MIN,N+1):
    if n + func(n) == N:
        ans.append(n)

print(len(ans))
for a in ans:
    print(a)