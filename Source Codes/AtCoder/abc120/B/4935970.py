a, b, k = map(int, input().split())
max = max(a, b)
ans = []
for i in range(1, max+1):
  if a % i == 0 and b % i == 0:
    ans.append(i)
print(ans[-(k)])