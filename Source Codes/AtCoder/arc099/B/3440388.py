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

def digit_sum(num:int, base:int) -> int:
    if num < base:
        return num
    else:
        return digit_sum(int(num/base), base) + (num % base)

def snuke(num: int):
    return num / digit_sum(num, 10)

k = ni()

snuke_nums = [i for i in range(1,10)]
res = 9
cur = 9

if k <= res:
    for s in snuke_nums[:k]:
        print(s)

else:
    while res != k:
        cur += 1
        
        cands = []
        for i in range(len(str(cur))):
            cands.append(int(str(cur)[:-i-1] + "9"*(i+1)))
            
        mi = float("inf")
        for c in cands:
            if snuke(c) < mi:
                cur = c
                mi = snuke(c)
                
        snuke_nums.append(cur)
        res += 1
        
    for s in snuke_nums:
        print(s)