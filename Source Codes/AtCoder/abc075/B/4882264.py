h,w=map(int,input().split())
s=[list(input()) for _ in range(h)]

for i in range(h):
  for j in range(w):
    if s[i][j]=='#':
      continue
    cnt=0
    for dx in [-1,0,1]:
      for dy in [-1,0,1]:
        if not(0<=dx+i<=h-1 and 0<=dy+j<=w-1):
          continue
        if s[i+dx][j+dy]=='#':
          cnt+=1
    s[i][j]=str(cnt)
for m in s:
  print(''.join(m))