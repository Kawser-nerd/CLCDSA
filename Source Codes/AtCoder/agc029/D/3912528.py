X,Y,N = list(map(int,input().split()))
l = []

for i in range(N):
  x,y = list(map(int,input().split()))
  l.append([x,y])
  
l.sort()

cnt = 0
ans = 0
for i in l:
  if i[0] > i[1]+cnt:
    ans = i[0]
    break
  elif i[0] == i[1]+cnt:
    cnt += 1

if ans != 0:
  print(ans-1)
else:
  print(X)