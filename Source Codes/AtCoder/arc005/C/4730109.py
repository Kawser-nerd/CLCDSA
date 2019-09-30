import sys
from collections import deque
input = sys.stdin.readline

H,W = map(int,input().split())
c = ['w'*(W+2)]+['w'+input().strip()+'w' for i in range(H)]+['w'*(W+2)]
smap = [[None]*(W+2) for i in range(H+2)]
angle = [[1,0],[-1,0],[0,1],[0,-1]]
q = deque()
cnt = 0

for i in range(H+2):
  for j in range(W+2):
    if c[i][j] == 's':
      q.append([i,j])
      smap[i][j] = 0

while(len(q)>0):
  x = q.popleft()
  cnt = smap[x[0]][x[1]]
  for i in angle:
    if c[x[0]+i[0]][x[1]+i[1]] == '.' and smap[x[0]+i[0]][x[1]+i[1]] == None:
      q.appendleft([x[0]+i[0],x[1]+i[1]])
      smap[x[0]+i[0]][x[1]+i[1]] = cnt
    elif cnt < 2 and c[x[0]+i[0]][x[1]+i[1]] == '#' and smap[x[0]+i[0]][x[1]+i[1]] == None:
      q.append([x[0]+i[0],x[1]+i[1]])
      smap[x[0]+i[0]][x[1]+i[1]] = cnt + 1
    elif c[x[0]+i[0]][x[1]+i[1]] == 'g':
      print('YES')
      exit()

print('NO')