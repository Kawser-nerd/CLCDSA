N = int(input())
moves=0
previous=0
exists=1
a = [0 for i in range(N)]
for i in range(N):
  a[i]=int(input())
if a[0]!=0:
  exists=0
for i in [N-j-1 for j in range(N)]:
  if a[i]>=previous:
    moves+=a[i]
  elif a[i]<previous-1:
    exists=0
  previous = a[i]
if exists==0:
  print(-1)
else:
  print(moves)