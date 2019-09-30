N=int(input())
s=input()
e=0
w=0
for i in s:
    if(i=='W'):
        w+=1
    elif(i=='E'):
        e+=1
ans=[0,0]
dp=[-1 for _ in range(N)]

for i in range(N):
    tmp=ans[1]
    if(s[i]=='W'):
        ans[1]+=1
    else:
        ans[0]+=1
    dp[i]=tmp+(e-ans[0])

print(min(dp))