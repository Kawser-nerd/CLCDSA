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

class BIT(object):
    def __init__(self, size):
        self.size = size+1
        self.bitree = [0]*self.size
        
    def addval(self, idx:int, val:int):
        while idx < self.size:
            self.bitree[idx] += val
            idx += idx&(-idx)
            
    def getsum(self, idx:int):
        ret = 0
        while idx > 0:
            ret += self.bitree[idx]
            idx -= idx&(-idx)
            
        return ret
    
    def reset(self):
        self.bitree = [0]*self.size


def val2ord(a: list, rev=False):
    dic = {ai: i for i, ai in enumerate(sorted(a, reverse=rev))}
    return [dic[ai] for ai in a]


n,k = li()
a = [ni() for _ in range(n)]

acc = [0] + list(accumulate(a))

b = [acci - i*k for i,acci in enumerate(acc)]
c = val2ord(b)

bitree = BIT(n+1)

ans = 0
for ci in c:
    bitree.addval(ci+1, 1)
    ans += bitree.getsum(ci+1)-1

print(ans)