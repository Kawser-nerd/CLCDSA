s = input() 
flag = 1
for i in range(len(s)):
  if not(s[i] == s[-i-1] or s[i] == '*' or s[-i-1] == '*'):
	  flag = 0
print("YES" if flag else "NO")