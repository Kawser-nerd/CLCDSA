s = str(input())
num = [str(i) for i in range(10)]
ans = ''
for i in s:
  if i in num:
    ans += i
print(ans)