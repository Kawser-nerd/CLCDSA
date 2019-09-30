import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from bisect import bisect_left

dic = dict()

n = ni()
a = []
for _ in range(n):
    a.append(ni())
    
b = sorted(a)

for i, ai in enumerate(a):
    dic[ai] = (i, bisect_left(b,ai))
    
cnt = 0
for ord1, ord2 in dic.values():
    if ord1%2 != ord2%2:
        cnt += 1
        
print(cnt // 2)