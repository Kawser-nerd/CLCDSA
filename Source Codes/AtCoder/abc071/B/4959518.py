s = list(input())
s.sort()
abc = 'abcdefghijklmnopqrstuvwxyz'
ans = 'None'

for i in range(26):
	if abc[i] in s:
		continue
	else:
		ans = abc[i]
		break
print(ans)