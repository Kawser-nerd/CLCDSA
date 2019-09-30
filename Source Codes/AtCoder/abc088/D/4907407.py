#?? ??????????????
#?????????????????????????????????????????????
#????????????(???+1??????????????)??????????
#????+1??????????????????

from collections import deque

H,W = map(int,input().split())
maze = [list(input()) for _ in range(H)]

white_panel_cnt = 0
for y in range(H):
    for x in range(W):
        if maze[y][x] == '.':
            white_panel_cnt += 1
que = deque()

#???????(1,1)?list???(0,0)??????
sx,sy,gx,gy = (0,0,W-1,H-1)
que.append((sx,sy))
distance_from_start = [[-1]*W for _ in range(H)]
distance_from_start[sy][sx] = 0
move = [[1,0],[-1,0],[0,1],[0,-1]]

def minimum_distance():
    while len(que) != 0:
        x,y = que.popleft()
        #for i in range(len(distance_from_start)):
            #print(distance_from_start[i])
        if x == gx and y == gy:
            return distance_from_start[y][x]
        for i in range(4):
            next_x = x + move[i][0]
            next_y = y + move[i][1]
            #print(next_x,next_y)
            if next_x < 0 or next_x >= W or next_y < 0 or next_y >= H or distance_from_start[next_y][next_x] != -1 or maze[next_y][next_x] == '#':
                continue
            #print(distance_from_start[y][x])
            distance_from_start[next_y][next_x] = distance_from_start[y][x] + 1
            que.append((next_x,next_y))
        #for i in range(len(distance_from_start)):
            #print(distance_from_start[i])

distance = minimum_distance()
#print('distance={}'.format(distance))
if distance == None:
    score = -1
else :
    score = white_panel_cnt-(distance+1)

print(score)