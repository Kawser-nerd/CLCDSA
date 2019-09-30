s=input()
start=-1
for i in range(len(s)):
	if start<0 and s[i]=='A':
		start=i
	if s[i]=='Z':
		goal=i
print(goal-start+1)