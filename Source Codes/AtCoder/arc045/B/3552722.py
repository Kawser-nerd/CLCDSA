n,m=map(int,input().split())
f=[0]*(n+2)
ss=[]
tt=[]
for _ in range(m):
    s,t=map(int,input().split())
    f[s]+=1
    f[t+1]-=1
    ss.append(s)
    tt.append(t)
for i in range(1,n+1):
    f[i]+=f[i-1]
for i in range(n+1):
    f[i] = 1 if f[i]==1 else 0
for i in range(1,n+1):
    f[i]+=f[i-1]
ans=[]
for i in range(m):
    if f[ss[i]-1]-f[tt[i]]==0:
        ans.append(i+1)
print(len(ans))
for i in ans:
    print(i)