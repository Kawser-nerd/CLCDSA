import sys
stdin = sys.stdin

sys.setrecursionlimit(10**5)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from itertools import accumulate

n,c = li()
x = []
v = []
for _ in range(n):
    xi,vi = li()
    x.append(xi)
    v.append(vi)

# ?????max
cw_dist = [0] + x
value_cum = [0] + list(accumulate(v))
cw_value = [value - dist for dist,value in zip(cw_dist, value_cum)]
cw_max = [0]
for i in range(1,n+1):
    cw_max.append(max(cw_max[-1], cw_value[i]))

# ??????max
ccw_dist = [0] + [c-xi for xi in x[::-1]]
value_cum2 = [0] + list(accumulate(v[::-1]))
ccw_value = [value - dist for dist,value in zip(ccw_dist, value_cum2)]
ccw_max = [0]
for i in range(1,n+1):
    ccw_max.append(max(ccw_max[-1], ccw_value[i]))
    
#
cands = [0]
for i in range(n+1):
    cand = max(cw_max[i],
               ccw_max[n-i],
               cw_max[i]+ccw_max[n-i] - min(cw_dist[i], ccw_dist[n-i]))
               
    cands.append(max(cands[-1],cand))

print(max(cands))