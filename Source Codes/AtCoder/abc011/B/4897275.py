s = input()
s = s.lower()
if len(s) >= 2:
	print(s[0].upper() + s[1:])
else:
    print(s[0].upper())