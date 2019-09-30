N = int(input())
L = []
for i in range(N):
  L.append(list(map(int,input().split())))
M = []
for i in range(N):
  M.append(list(map(int,input().split())))
L = sorted(L, key = lambda x:x[1])
L.reverse()
M.sort()
LT = [True]*N
MT = [True]*N
ans = 0
for i in range(N):
  curx = M[i][0]
  cury = M[i][1]
  for j in range(N):
    if LT[j] == True:
      if MT[i] == True:
        if curx >= L[j][0] and cury >= L[j][1]:
          LT[j] = False
          ans += 1
          MT[i] = False
print(ans)