N=int(input())
S=input()
ans=0
key=0
for i in range(len(S)):
    if S[i]=='I':
        key+=1
    else:
        key-=1
    ans=max(ans,key)
        
print(ans)