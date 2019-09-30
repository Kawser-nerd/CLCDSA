from collections import deque

row,col = map(int,input().split())
sy,sx = map(int,input().split())
gy,gx = map(int,input().split())
c = [input() for i in range(row)]

w = [[1,0],[-1,0],[0,1],[0,-1]]

queue = deque()
check = [[-1 for i in range(col)] for k in range(row)]

check[sy][sx] = 0

queue.append([sy,sx])

while len(queue) != 0 :
    v = queue.popleft()

   
    for move in w:
        y = v[0]+move[0]
        x = v[1]+move[1]
            
        if c[y-1][x-1] == '.' and check[y][x] == -1:
         
            check[y][x] = check[v[0]][v[1]] + 1
            queue.append([y,x])


print(check[gy][gx])