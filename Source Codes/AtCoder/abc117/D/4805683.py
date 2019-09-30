N,K=map(int,input().split())
a=list(map(int,input().split()))
l=max( len(bin(K)) ,len(bin(max(a))) )-2

K=bin(K)[2:].zfill(l)[::-1]
a=[bin(a[i])[2:].zfill(l)[::-1] for i in range(N)]
val=[[0,0] for i in range(l)]

for i in range(N):
    for j in range(l):
        if a[i][j]=="0": val[j][0]+=1
        else: val[j][1]+=1
        



tmp=0
for j in range(l):
    tmp+=(N-val[j][int(K[j])])*2**j

ans=tmp

for i in range(l):
    tmp=0
    if K[i]=="1":
        for j in range(i):
            tmp+=max(val[j])*2**j
        
        tmp+=val[i][1]*2**i
        
        for j in range(i+1,l):
            tmp+=(N-val[j][int(K[j])])*2**j
            
    ans=max(ans,tmp)
    
print(ans)