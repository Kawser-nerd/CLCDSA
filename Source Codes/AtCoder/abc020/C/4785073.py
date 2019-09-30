from collections import deque
h,w,t = map(int,input().split())
s = [input() for i in range(h)]

for i in range(h):
  for j in range(w):
    if s[i][j] == "S":
      s_h,s_w = i,j
    if s[i][j] == "G":
      g_h,g_w = i,j
      

def bfs(x):
  que = deque()
  time = [[float("inf")]*w for i in range(h)]
  time[s_h][s_w] = 0
  que.append([s_h,s_w])
  
  while que:
    [pos_h,pos_w] = que.popleft()
    for next_pos_h,next_pos_w in [[pos_h+1,pos_w],[pos_h-1,pos_w],[pos_h,pos_w+1],[pos_h,pos_w-1]]:
      if 0 <= next_pos_h <= h-1 and 0 <= next_pos_w <= w-1:
        if s[pos_h][pos_w] == "#":
          if time[next_pos_h][next_pos_w] > time[pos_h][pos_w] + x:
            time[next_pos_h][next_pos_w] = time[pos_h][pos_w] + x
            que.append([next_pos_h,next_pos_w])
        else:
          if time[next_pos_h][next_pos_w] > time[pos_h][pos_w] + 1:
            time[next_pos_h][next_pos_w] = time[pos_h][pos_w] + 1
            que.append([next_pos_h,next_pos_w])
  if time[g_h][g_w] <= t:
    return True
  else:
    return False

ng = 10**9+1
ok = 0

while abs(ok-ng) > 1:
  mid = (ok+ng)//2
  if bfs(mid):
    ok = mid
  else:
    ng = mid

print(ok)