s = input()
ans = ''
i = 1
for c in s:
  if (i % 2 == 1):
    ans += c
  i += 1

print(ans)