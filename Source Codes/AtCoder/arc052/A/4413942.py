s = input()
num = "1234567890"
ans = ""
for i in s:
  if i in num:
    ans += i
print(int(ans))