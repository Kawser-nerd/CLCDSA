n, m = map(int, input().split())

# n+k = m//2-k, 2k = m//2 - n, k = (m//2 - n) // 2

# min(n+k, (m-2k)//2) = min(n+k, m//2 - k)

p = (m // 2 - n) // 2
ans = min(n, m//2)
for k in range(max(0, p-10), p+10):
  v = min(n+k, m//2-k)
  if v >= 0:
    ans = max(ans, v)
  
print(ans)