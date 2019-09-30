n = int(input())
s = list(input())
ans = 0
for i in range(1,n-1):
  x = s[:i]
  y = s[i:]
  ans = max(ans, len(set(x) & set(y)))
print(ans)