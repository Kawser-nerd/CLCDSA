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

n,m = li()
a = [0] + [ni() for _ in range(n)]
pat = [0]*(n+1)
pat[1] = 1
pat_cum = [0]*(n+1)
pat_cum[0] = 0
pat_cum[1] = 1

MOD = 10**9+7

left = 0

sup = set([a[1]])
for i, ai in enumerate(a[2:]):
    j = i+2
    if ai not in sup:
        sup.add(ai)
        
    else:
        idx = left+1
        while a[idx] != ai:
            sup.remove(a[idx])
            idx += 1

        left = idx
        
    pat[j] = pat_cum[j-1] - (-1 if not left else pat_cum[left-1])
    pat[j] %= MOD
    pat_cum[j] = pat_cum[j-1] + pat[j]
    pat_cum[j] %= MOD
    
print(pat[n])