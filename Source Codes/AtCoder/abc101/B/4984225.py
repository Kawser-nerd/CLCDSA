N=input()
SN=0
for n in N:
	SN+=int(n)
print("Yes" if int(N)%SN == 0 else "No")