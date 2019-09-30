s = input()
r = s[::-1]
for i in range(len(s)):
  if s[i] != r[i] and s[i] != "*" and r[i] != "*":
    print("NO")
    exit()
print("YES")