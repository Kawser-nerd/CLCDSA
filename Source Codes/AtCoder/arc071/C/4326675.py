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

s = ns()
t = ns()
q = ni()

sa = [0]
sb = [0]
ta = [0]
tb = [0]

for si in s:
    if si == "A":
        sa.append(sa[-1] + 1)
        sb.append(sb[-1])
        
    else:
        sa.append(sa[-1])
        sb.append(sb[-1] + 1)
        
for ti in t:
    if ti == "A":
        ta.append(ta[-1] + 1)
        tb.append(tb[-1])
        
    else:
        ta.append(ta[-1])
        tb.append(tb[-1] + 1)
        
for _ in range(q):
    a,b,c,d = li()
    
    sanum = sa[b] - sa[a-1]
    sbnum = sb[b] - sb[a-1]
    
    tanum = ta[d] - ta[c-1]
    tbnum = tb[d] - tb[c-1]
    
    sanum += 2*sbnum
    tanum += 2*tbnum
    
    if sanum%3 == tanum%3:
        print('YES')
    else:
        print('NO')