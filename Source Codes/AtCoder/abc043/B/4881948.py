s = input()
 
ans = ''
for i in range(len(s)):
	if s[i:i+1]=='0':
		ans += '0'
	elif s[i:i+1]=='1':
		ans += '1'
	elif s[i:i+1]=='B':
		ans = ans[:-1]
 
print(ans)