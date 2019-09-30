N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
kai = set()
ans = 0
for m in range(N):
  for i in range(50,0,-1):
    kai.add(i)
  amari = [] 
  for i in kai:
    are = a[m] % i
    amari.append(are)
  for k in range(len(amari)):
    for i in kai:
      are = amari[k] % i
      amari.append(are)
  if b[m] in amari:
    ann = 0
  else:
    ans = -1

for p in range(50,0,-1):
  kai.remove(p)
  for j in range(N):
    amari = [] 
    for i in kai:
      are = a[j] % i
      amari.append(are)
    for k in range(len(amari)):
      for i in kai:
        are = amari[k] % i
        amari.append(are)
    if b[j] in amari:
      ann = 0
    else:
      kai.add(p)
if ans == -1:
   print(-1)
elif a == b:
  print(0)
else:
  ans = 0
  for i in kai:
    ans += 2 ** i
  print(ans)