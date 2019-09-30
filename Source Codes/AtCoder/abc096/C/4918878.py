H, W = map(int, input().split())
S = []
for _ in range(H):
  S.append(input())

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
  
flg = False
for i in range(H):
  for j in range(W):
    if S[i][j] == "#":
      flg = False
      for k in range(4):
        if i+dy[k]>=0 and i+dy[k]<H and j+dx[k]>=0 and j+dx[k]<W:
          if S[i+dy[k]][j+dx[k]]=='#':
            flg = True
      if flg == False:
        print("No")
        exit()
print("Yes")