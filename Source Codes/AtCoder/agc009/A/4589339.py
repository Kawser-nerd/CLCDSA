N = int(input())
L = []
for i in range(N):
  L.append(list(map(int,input().split())))
cnt = 0
for i in range(N):
  if L[N-i-1][0]%L[N-i-1][1] != 0:
    cnt += L[N-i-1][1]-(L[N-i-1][0]%L[N-i-1][1])
  else:
    None
  L[N-i-2][0] += cnt
print(cnt)