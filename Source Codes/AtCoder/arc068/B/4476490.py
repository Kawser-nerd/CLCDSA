N = int(input())
L = list(map(int,input().split()))
L.sort()
L.append(0)
EVEN = 0
ODD = 0
cnt = 1
cur = L[0]
i = 0
while i < N:
  if L[i] == L[i+1]:
    cnt += 1
    i += 1
  else:
    if cnt%2 == 0:
      EVEN += 1
    else:
      ODD += 1
    cur = L[i+1]
    i += 1
    cnt = 1
if EVEN%2 == 0:
  print(EVEN+ODD)
else:
  print(EVEN+ODD-1)