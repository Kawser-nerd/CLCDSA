from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
aa = [int(input()) for i in range(N)]

cnt = defaultdict(lambda:[0,0])
for i,a in enumerate(aa):
    if i%2 == 0:
        cnt[a][0] += 1
    else:
        cnt[a][1] += 1

aa.sort()
ans = 0
for i,a in enumerate(aa):
    ev,od = cnt[a]
    if i%2 == 0:
        if ev == 0:
            ans += 1
            cnt[a][0] -= 1
        else:
            cnt[a][1] -= 1
    else:
        if od == 0:
            ans += 1
            cnt[a][0] -= 1
        else:
            cnt[a][1] -= 1

print(ans//2)