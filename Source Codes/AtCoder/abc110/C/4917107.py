s = input()
t = input()
a = "abcdefghijklmnopqrstuvwxyz"

flag = 0
i = 0 
while i < len(s):
	if s[i] != t[i]:
		if t[i] in a:
			c = s[i]
			s = s.replace(c, "1")
			s = s.replace(t[i], c)
			s = s.replace("1", t[i])
			a = a.replace(t[i], "1")
		else:
			break
	i += 1
if s == t:
	print("Yes")
else:
	print("No")