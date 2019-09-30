S=list(input())
l=len(S)
for i in range(1,l//2):#len=2*i
	if all([S[j]==S[j+i] for j in range(i)]):
		ans=2*i
print(ans)