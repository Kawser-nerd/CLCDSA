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

def compress(xy_row: list, x_compressor, y_compressor):
    xy_comped = []
    for xi, yi in xy_row:
        xy_comped.append((x_compressor[xi], y_compressor[yi]))
        
    return xy_comped

def decompress(comped: list, x_decomp, y_decomp):
    xy_decomped = []
    for xi, yi in comped:
        xy_decomped.append((x_decomp[xi], y_decomp[yi]))
        
    return xy_decomped

n,k = li()
xy_row = [tuple(li()) for _ in range(n)]

x_row = [x for x, _ in sorted(xy_row, key=lambda x:x[0])]
y_row = [y for _, y in sorted(xy_row, key=lambda y:y[1])]

x_compressor = {xi: i+1 for i, xi in enumerate(x_row)}
y_compressor = {yi: i+1 for i, yi in enumerate(y_row)}
x_decomp = {i+1: xi for i, xi in enumerate(x_row)}
y_decomp = {i+1: yi for i, yi in enumerate(y_row)}

xy_comped = compress(xy_row, x_compressor, y_compressor)


grid = [[0]*(len(xy_comped)+1) for _ in range(len(xy_comped)+1)]
for xi, yi in xy_comped:
    grid[xi][yi] += 1
    
grid = cum_2d(grid)

ans = float('inf')

for xleft in range(1,n+1):
    for xright in range(xleft, n+1):
        for ylow in range(1,n+1):
            for yhigh in range(ylow, n+1):
                if grid[xright][yhigh] - grid[xright][ylow-1] - grid[xleft-1][yhigh] + grid[xleft-1][ylow-1] < k:
                    continue
                
                xnw = x_decomp[xleft]
                xne = x_decomp[xright]
                
                yne = y_decomp[yhigh]
                yse = y_decomp[ylow]

                ans = min(ans, (xne-xnw)*(yne-yse))
                
print(ans)