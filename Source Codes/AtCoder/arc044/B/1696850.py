MOD=int(1e9+7)
N=int(input())
A=list(map(int,input().split()))
c = [0] * N
for x in A:
  c[x] += 1
ans = 1 if A[0] == 0 and c[0] == 1 else 0
for i in range(1,N):
  if c[i] > 0:
    ans *= pow(2, ((c[i] * (c[i]-1)) // 2), MOD) * pow((pow(2, c[i-1], MOD)-1), c[i], MOD)
    ans %= MOD
print(int(ans))