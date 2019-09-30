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
d = [[0] + list(li()) for _ in range(n)]
q = ni()
p = [ni() for _ in range(q)]

d.insert(0, [0 for _ in range(n+1)])

def cum_2d(field:list):
    row = len(field)
    col = len(field[0])
    
    # ???????
    for r in range(row):
        for c in range(col-1):
            field[r][c+1] += field[r][c]
    
    # ???????
    for c in range(col):
        for r in range(row-1):
            field[r+1][c] += field[r][c]
            
    return field


cum_d = cum_2d(d)

dic = {i: 0 for i in range(n*n + 1)}

for left in range(0,n):
    for top in range(0,n):
        for right in range(left+1, n+1):
            for bottom in range(top+1, n+1):
                area = (right-left) * (bottom-top)
                temp = cum_d[right][bottom] + cum_d[left][top] - cum_d[right][top] - cum_d[left][bottom]
                dic[area] = max(dic[area], temp)
                
maxs = [0 for _ in range(n*n+1)]
for i in range(1, n*n+1):
    maxs[i] = max(dic[i], maxs[i-1])
    
for qi in p:
    print(maxs[qi])