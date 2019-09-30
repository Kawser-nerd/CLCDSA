s = input()
s1,s2 = s[:(len(s)-len(s)%2)//2],s[(len(s)+len(s)%2)//2:][::-1]
num = 0
for i in range(len(s1)):
	if s1[i] != s2[i]: num+=1
	if num==2: break
if num==0: print(len(s1)*50)
elif num==1: print(len(s)*25-2)
else: print(len(s)*25)