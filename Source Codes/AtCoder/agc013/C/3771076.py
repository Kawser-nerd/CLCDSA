n,l,t =  map(int,input().split())
x = [list(map(int,input().split())) for i in range(n)]
las = [0]*n
for i in range(n):
  las[i] = (x[i][0]+(t if x[i][1]==1 else -t))%l
han = []
for i in range(1,n):
  if x[i][1] != x[0][1]:
    if x[0][1] ==1:
      han.append(x[i][0]-x[0][0])
    else:
      han.append(l-x[i][0]+x[0][0])
su = 0
t*=2
su += (len(han))*(t//l)
t%=l
for i in han:
  if t> i:
    su+=1
if x[0][1] == 2:
  su=(-su)%n
else:
  su%=(n)
ii = las[0]
las.sort()
basyo = las.index(ii)
for i in range(basyo+1,n):
  if las[basyo] == las[i]:
    if x[0][1] == 2:
      basyo+=1
  break
las.extend(las)
ans = [0]*n
z = 0
for i in range(basyo,basyo+n):
  ans[(su+z)%n] = las[i]
  z += 1
for i in ans:
  print(i)