N,C,K = map(int,input().split())
T = [int(input()) for _ in range(N)]
T.sort()

time=T[0]
count = 1
ans = 0

for i in range(1,N):
  if T[i]-time>K or count==C:
    time = T[i]
    count = 1
    ans += 1
  else:
    count += 1
if count>0:
  ans += 1
print(ans)