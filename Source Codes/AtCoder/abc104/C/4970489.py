D, G = map(int, input().split())
P = []
C = []
for i in range(D):
  p, c = map(int, input().split())
  P.append(p)
  C.append(c)
ans = 10*100
for i in range(2**D):
  rest = G
  cnt = 0
  maxdgt = -1
  for j in range(D):
    if i>>j & 1:
      rest -= P[j]*(j+1)*100+C[j]
      cnt += P[j]
    else:
      maxdgt = j
  if rest <= 0:
    ans = min(ans, cnt)
  elif rest > (P[maxdgt]-1)*(maxdgt+1)*100:
    continue
  else:
    ans = min(ans, cnt+(rest/100-1)//(maxdgt+1)+1)
print(int(ans))