from collections import deque
R,C = map(int,input().split())
sy,sx = 1,1  #???????
gy,gx = R,C  #??????
L = []
for i in range(R):
  L.append(list(input()))   #??????????
dy_dx = [[1,0],[-1,0],[0,1],[0,-1]]   #??
black = 0
for i in range(R):
  for j in range(C):
    if L[i][j] == '#':
      black += 1
que = deque([[sy-1,sx-1]])   #que??????????????????????????????
L[sy-1][sx-1] = 0  #????????????????0?
while len(que) > 0:  #que????????
  cur = que.popleft()   #que???????
  for i in range(4):  #??????????????????
    if 0 <= cur[0]+dy_dx[i][0] <= R-1 and 0 <= cur[1]+dy_dx[i][1] <= C-1:  #????????????????
      if L[cur[0]+dy_dx[i][0]][cur[1]+dy_dx[i][1]] == '.':  #?????????????
        L[cur[0]+dy_dx[i][0]][cur[1]+dy_dx[i][1]] = L[cur[0]][cur[1]]+1  #???????????+1????
        que.append([cur[0]+dy_dx[i][0],cur[1]+dy_dx[i][1]])   #que?????????????????
if L[gy-1][gx-1] == '#':
  print(-1)
elif L[gy-1][gx-1] == '.':
  print(-1)
else:
  print(R*C-L[gy-1][gx-1]-1-black)