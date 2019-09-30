#103

S=input()
T=input()
s=len(S)
if S==T:
    print('Yes')
    exit()
for i in range(s+1):
    S=S[-1]+S[0:s-1]
    if S==T:
        print('Yes')
        exit()
print('No')