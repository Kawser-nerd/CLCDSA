N,M = map(int,input().split())
L = []
for i in range(M):
  L.append(list(map(int,input().split())))
ball = [1]*N
aka = [False]*N
aka[0] = True
for i in range(M):
  if aka[L[i][0]-1] == True:
    aka[L[i][1]-1] = True
  ball[L[i][0]-1] -= 1
  if ball[L[i][0]-1] == 0:
    aka[L[i][0]-1] = False
  ball[L[i][1]-1] += 1
ans = 0
for i in range(N):
  if aka[i] == True:
    ans += 1
print(ans)