#the BFS
from collections import deque

R,C = (int(_) for _ in input().split())
sy,sx = (int(_) for _ in input().split())
gy,gx = (int(_) for _ in input().split())
maze = [list(input()) for _ in range(R)]
distance_from_start = [[-1]*C for _ in range(R)]

move = [[1,0],[-1,0],[0,1],[0,-1]]

que = deque()
que.append((sx,sy))
distance_from_start[sy-1][sx-1] = 0
def minimum_distance():
    while len(que) != 0:
        x,y = que.popleft()
        for i in range(4):
            next_x = x + move[i][0]
            next_y = y + move[i][1]
            if next_x <= 0 or next_x > C or next_y <= 0 or next_y > R or distance_from_start[next_y-1][next_x-1] != -1 or maze[next_y-1][next_x-1] == "#":
                #print(maze[next_y-1][next_x-1])
                continue
            distance_from_start[next_y-1][next_x-1] = distance_from_start[y-1][x-1] + 1
            que.append((next_x,next_y))
        #print(que)
#print('R={} C={}'.format(R,C))
#print(que)
minimum_distance()
print(distance_from_start[gy-1][gx-1])