S = "!"+input()
a,b,c,d = map(int,input().split())
res = ""
for i in range(len(S)):
	if i == a or i == b or i == c or i == d:
		res += S[i]+'"'
	else:
		res += S[i]
print(res.replace('!',''))