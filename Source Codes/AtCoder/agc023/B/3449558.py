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
 
n = ni()
grid = []
 
for _ in range(n):
    s = ns()
    s = s+s
    grid.append(s)
    
for i in range(n):
    grid.append(grid[i])
    
vert = []
hrzn = []
 
for i in range(2*n):
    hrzn.append(grid[i])
    
for j in range(2*n):
    temp = ""
    for i in range(2*n):
        temp += grid[i][j:j+1]
        
    vert.append(temp)
    
    
ans = 0
 
for a in range(n):
    for b in range(1):
        
        ok = True
        for i in range(n-1):
 
            if vert[b+i][a+i:a+n] != hrzn[a+i][b+i:b+n]:
                ok = False
                break
                
        if ok:
            ans += 1
            
print(ans*n)