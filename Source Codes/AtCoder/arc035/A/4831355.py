s = input() 
for i in range(len(s)):
  if s[i] == s[-i-1] or s[i] == '*' or s[-i-1] == '*':
    continue
  else:
    print("NO")
    exit()
print("YES")