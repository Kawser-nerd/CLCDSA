H, W = map(int,input().split())

cnt = 0
for _ in range(H):
  cnt += input().count("#")
ans = "Impossible"
if(cnt == H+W-1):
  ans = "Possible"
print(ans)