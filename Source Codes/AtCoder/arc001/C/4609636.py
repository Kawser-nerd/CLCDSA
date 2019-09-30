import sys
 
M = [list(input()) for i in range(8)]
 
def check(y, x):
    for i in range(1, 8):
        y1 = [y  , y  , y-i, y-i, y-i, y+i, y+i, y+i]
        x1 = [x-i, x+i, x-i, x  , x+i, x-i, x  , x+i]
 
        for Y, X in zip(y1, x1):
            if 0<=Y<=7 and 0<=X<=7 and M[Y][X] == "Q":
                return 0
    return 1
 
 
def dfs(n, ny):
    if n == 0:
        for m in M:
            print("".join(m))
        sys.exit()
 
    for y in range(ny, 8):
        for x in range(8):
            if M[y][x] == 'Q':
                continue
            if check(y, x) == 0:
                continue
            M[y][x] = 'Q'
            dfs(n-1, y+1)
            M[y][x] = '.'
 
for y in range(8):
    for x in range(8):
        if M[y][x] == "Q" and check(y, x) == 0:
            print("No Answer")
            sys.exit()
 
dfs(5, 0)
print("No Answer")