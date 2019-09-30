n = int(input())
a = list(map(int,input().split()))
rui = [0] * (n+1)
for i in range(n):
  rui[i+1] = rui[i] + a[i]
ans = float("inf")
for i in range(1,n):
  ans = min(ans,abs(rui[i]-(rui[n]-rui[i])))
print(ans)