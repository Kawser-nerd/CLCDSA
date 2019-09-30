N, C, K = map(int,input().split())
T = []
for _ in range(N):
  T.append(int(input()))
T.sort()
cnt=1
s=0
for i in range(1,N):
  if (T[i] > T[s]+K) or (i==s+C):
    cnt += 1
    s=i
print(cnt)