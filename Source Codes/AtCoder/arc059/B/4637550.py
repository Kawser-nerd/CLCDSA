s = input()
if s[0] == s[1]:
  print(1,2)
  exit()
for i in range(2,len(s)):
  if s[i] == s[i-1] or s[i] == s[i-2]:
    print(i-1,i+1)
    break
else:
  print(-1,-1)