s = input() 
t = s[::-1]
for i in range(len(s)):
	if s[i] == t[i] or s[i] == '*' or t[i] == '*':
		continue
	else:
		print("NO")
		exit()
print("YES")