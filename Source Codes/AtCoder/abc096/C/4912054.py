H, W = map(int, input().split())
s = [list(input()) for i in range(H)]
check = [[False]*W]*H
dx = -1,0,1,0
dy = 0,-1,0,1

for h in range(H):
  for w in range(W):
    bcount = 0 #??????????
    if s[h][w] == "#":
      for i in range(4):
        if 0 <= h+dx[i] <= H-1 and 0 <= w+dy[i] <= W-1 and s[h+dx[i]][w+dy[i]] == "#":
            bcount += 1
      if bcount == 0:
        print("No")
        exit()
print("Yes")