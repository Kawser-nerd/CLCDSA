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

def search(east:int, south:int, west:int, north:int, xy:list, memo={}):
    if memo[(east,south,west,north)] != 0:
        return memo[(east,south,west,north)]
    
    cands = []
    for xcand,ycand in xy:
        if east <= xcand <= west and south <= ycand <= north:
            cands.append((xcand, ycand))
        
    if len(cands) == 0:
        return 0
    
    temp = 0
    for xnex, ynex in cands:
        temp = (west-east) + (north-south) + 1\
             + search(east, ynex+1, xnex-1, north,xy,memo)\
             + search(xnex+1, ynex+1, west, north,xy,memo)\
             + search(xnex+1, south, west, ynex-1,xy,memo)\
             + search(east, south, xnex-1, ynex-1,xy,memo)
             
        memo[(east, south, west, north)] = max(memo[(east,south,west,north)], temp)
        
    return memo[(east, south, west, north)] 

from collections import defaultdict

memo = defaultdict(int)

w,h = li_()
n = ni()
machine = [list(li_()) for _ in range(n)]

ans = search(0,0,w,h,machine,memo)

print(ans)