n = int(input())
s = input()
ans = 0
for i in range(1,n):
  x = s[:i]
  y = s[i:]
  ans = max(ans, len(set(x) & set(y)))
print(ans)