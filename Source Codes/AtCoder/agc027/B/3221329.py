from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N,X = inpl()
xx = inpl()
sum_xx = [0]
tmp = 0
for x in xx:
    tmp += x
    sum_xx.append(tmp)

ans = INF
for k in range(1,N+1):  #????????
    tmp = X*(k+N)
    i = 0
    l = N-k
    r = N
    while True:
        if i <= 1: cost = 5
        else: cost = 3 + i*2
        if l >= 0:
            tmp += (sum_xx[r] - sum_xx[l])*cost
        else:
            tmp += (sum_xx[r] - sum_xx[0])*cost
            break
        l -= k
        r -= k
        i += 1
    ans = min(ans,tmp)

print(ans)