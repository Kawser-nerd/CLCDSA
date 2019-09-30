s = input() + " "
num = list(map(int, input().split()))
t = ""
for i in range(len(s)):
  if i in num:
    t += "\""
  t += s[i]
print(t[:-1])