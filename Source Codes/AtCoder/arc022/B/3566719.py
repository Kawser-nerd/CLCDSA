n = int(input())
a = list(map(int,input().split()))
b = [0] * n
yo = set()
ans = 0
migi = 0
hida = 0
while migi < n:
  yo.add(a[migi])
  if migi == hida:
    hida += 1
  if hida < n and a[hida] not in yo:
    yo.add(a[hida])
    hida += 1
  else:
    ans = max(ans,len(yo))
    yo.remove(a[migi])
    migi += 1
print(ans)