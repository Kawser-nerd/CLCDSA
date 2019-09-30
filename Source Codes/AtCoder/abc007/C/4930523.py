from collections import deque

r,c=map(int,input().split())
root = [[None for __ in range(c)] for __ in range(r)]

sx,sy=map(int,input().split())
gx,gy=map(int,input().split())
sy-=1
sx-=1
gy-=1
gx-=1


m = []
for i in range(r):
    m.append(list(input()))

root[sx][sy] = 0
celx=deque()
cely=deque()
x = sx
y = sy

while root[gx][gy] == None:
    #down
    if x != 0 and m[x-1][y] != '#' and root[x-1][y] == None:
        root[x-1][y] = root[x][y] + 1
        celx.append(x-1)
        cely.append(y)
    
    #up
    if x != r-1 and m[x+1][y] != '#' and root[x+1][y] == None:
        root[x+1][y] = root[x][y] + 1
        celx.append(x+1)
        cely.append(y)
    
    #left
    if y != 0 and m[x][y-1] != '#' and root[x][y-1] == None:
        root[x][y-1] = root[x][y] + 1
        celx.append(x)
        cely.append(y-1)
        
    #right
    if y != c-1 and m[x][y+1] != '#' and root[x][y+1] == None:
        root[x][y+1] = root[x][y] + 1
        celx.append(x)
        cely.append(y+1)
    
    x = celx.popleft()
    y = cely.popleft()
    
print(root[gx][gy])