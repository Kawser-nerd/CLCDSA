x,y = map(int,input().split())
L = [y-x,y+x+1,-y-x+1,-y+x+2]
M = []
for i in range(4):
  if L[i] > 0:
    M.append(L[i])
print(min(M))