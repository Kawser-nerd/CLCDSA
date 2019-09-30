s = str(input())
c = 0
for i in range(len(s)//2):
    if s[i] == s[len(s)-1] or s[i] == '*' or s[len(s)-1] == '*':
        c += 1
if c == len(s)//2:
	print("YES")
else:
	print("NO")