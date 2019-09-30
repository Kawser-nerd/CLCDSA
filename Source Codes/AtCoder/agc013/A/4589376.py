N = int(input())
L = list(map(int,input().split()))
L.append(0)
cur = L[0]
fugou = '±'
for i in range(1,N):
  if L[i] > cur:
    if not i == N:
      fugou = '+'
      break
  elif L[i] < cur:
    if not i == N:
      fugou = '-'
      break
if fugou == '±':
  print(1)
else:
  ans = 0
  for i in range(N):
    if fugou == '+':
      if cur > L[i]:
        fugou = '±'
        ans += 1
    elif fugou == '-':
      if cur < L[i]:
        fugou = '±'
        ans += 1
    else:
      if cur < L[i]:
        fugou = '+'
      elif cur > L[i]:
        fugou = '-'
    cur = L[i]
  print(ans+1)