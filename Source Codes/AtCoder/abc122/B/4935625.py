s = input()
n = len(s)
ans = 0
for i in range(n):
  for j in range(i, n):
    if all('AGCT'.count(c) for c in s[i:j+1]):
      ans = max(ans, j-i+1)
print(ans)