N, A, B = map(int, input().split())
ans = 0
x = list(map(int, input().split()))
for i in range(len(x)-1):
  ans += min(B, (x[i+1]-x[i]) * A)
print(ans)