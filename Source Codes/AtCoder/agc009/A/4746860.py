N = int(input())
A = []
B = []
for _ in range(N):
  a,b = map(int,input().split())
  A.append(a)
  B.append(b)

ans = 0
for i in range(N-1,-1,-1):
  ans += (B[i]-(A[i]+ans))%B[i]
print(ans)