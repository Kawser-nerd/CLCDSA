H,W,h,w = map(int,input().split())
if H % h == 0 and W % w == 0:
  print("No")
else:
  print("Yes")
  ans = [[1000] * W for i in range(H)]
  num = 0
  for i in range(h-1,H,h):
    for j in range(w-1,W,w):
      ans[i][j] = -(h * w-1) * 1000-1
      num += 1
  for nu in ans:
    print(" ".join(map(str,nu)))