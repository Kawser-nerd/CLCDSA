n = int(input())
ans = "No"

for i in range(n // 4 + 1):
  for j in range(n // 7 + 1):
    if 4 * i + 7 * j == n:
      ans = "Yes"
      break
  else:
    continue
  break
print(ans)