s = input()
ss = []
for i in range(len(s)):
	if i%2 == 0:
		ss.append(s[i])
print(''.join(ss))