s = input()
num = ""
for i in range(len(s)):
  if s[i] in "0123456789":
    num += s[i]
print(num)