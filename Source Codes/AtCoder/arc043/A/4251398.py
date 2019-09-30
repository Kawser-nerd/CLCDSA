N,A,B = map(int,input().split())
L = []
for i in range(N):
  L.append(int(input()))
L.sort()
if L[0]-L[N-1] == 0:
  print(-1)
else:
  P = B/(L[N-1]-L[0])
  print(P,A-P*sum(L)/N)