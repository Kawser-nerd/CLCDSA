N=int(input())
T=list(map(int,input().split()))
M=int(input())
ans=[]

for i in range(M):
    p,x=map(int,input().split())
    tmp=list(T)
    tmp[p-1]=x
    ans.append(sum(tmp))
    
for i in range(M):
    print(ans[i])