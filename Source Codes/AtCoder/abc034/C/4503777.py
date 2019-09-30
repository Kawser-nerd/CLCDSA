W,H = map(int,input().split())
bunshi = 1
bunbo = 1
for i in range(2,H+W-1):
  bunshi = (bunshi*i)%(10**9+7)
for j in range(2,H):
  bunbo = (bunbo*j)%(10**9+7)
for l in range(2,W):
  bunbo = (bunbo*l)%(10**9+7)
print((bunshi*pow(bunbo,10**9+5,10**9+7))%(10**9+7))