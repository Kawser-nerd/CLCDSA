S=input()
n=len(S)
ans=2*n-2
for i in range(1,n-1):
    if S[i]=='U':
        ans+=n+i-1
    else:
        ans+=2*n-i-2
print(ans)