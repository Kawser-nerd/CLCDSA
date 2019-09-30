N = int(input())
di = [int(input()) for n in range(N)]

di = sorted(di, reverse=True)
ans = 0
for i in range(N):
  if i < N-1 and di[i] == di[i+1]:
    i = i + 1
    continue
  ans += 1
  
print(ans)