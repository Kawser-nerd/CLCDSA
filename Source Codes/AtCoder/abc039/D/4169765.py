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

h,w = li()
s = [lc() for _ in range(h)]

nei = []
for i in range(-1,2):
    for j in range(-1,2):
        nei.append((i,j))

# ???
black = []
white = []
for row in range(h):
    for col in range(w):
        if s[row][col] == '#':
            black.append((row,col))
        else:
            white.append((row,col))

# ???
for row, col in white:
    for di,dj in nei:
        if 0<=row+di<h and 0<=col+dj<w:
            s[row+di][col+dj] = '.'
    
# ???????????
ex = True
for row,col in black:
    blackex = False
    for di,dj in nei:
        if 0<=row+di<h and 0<=col+dj<w:
            if s[row+di][col+dj] == '#':
                blackex = True
            
    if not blackex:
        ex = False
        break

if ex:
    print('possible')
    for row in s:
        print("".join(row))
else:
    print('impossible')