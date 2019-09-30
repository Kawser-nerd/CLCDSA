N=int(input())
S=input()
ans =0
for i in range(N+1):
    tmp=len(set(S[0:i])&set(S[i:]))
    if tmp>ans:
        ans=tmp
print(ans)