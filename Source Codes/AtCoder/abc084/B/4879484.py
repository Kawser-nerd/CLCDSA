a,b = map(int,input().split())
s = input()
bango = ['0','1','2','3','4','5','6','7','8','9']
answer ='No'
count = 0
if s[a] == '-':
	s = s[:a]+s[a+1:]
	for i in range(len(s)):
		if s[i] in bango:
			count +=1
	if count == len(s):
		answer = 'Yes'
print(answer)