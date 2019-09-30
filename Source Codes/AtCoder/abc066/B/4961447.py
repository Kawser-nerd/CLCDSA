s = input()
s = s[:len(s)-2]
while s[:len(s)//2] != s[len(s)//2:]:
	s = s[:len(s)-2]
print(len(s))