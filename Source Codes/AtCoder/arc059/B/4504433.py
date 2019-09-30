#ARC059D
S=input()
c={}
for i in [chr(ord('a') + i) for i in range(26)]:
	c[i]=0
for i in range(len(S)):
	if i<3:
		c[S[i]]+=1
		if c[S[i]]>=2:
			print(1,i+1)
			exit()
	else:
		c[S[i-3]]-=1
		c[S[i]]+=1
		if c[S[i]]>=2:
			print(i-1,i+1)
			exit()
print(-1,-1)