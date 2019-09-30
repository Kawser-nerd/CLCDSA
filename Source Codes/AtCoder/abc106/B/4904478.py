N=int(input())

ans=0
for i in range(1,N+1):
    if i%2==1:
        tmp=0
        for j in range(1,i+1):
            if i%j==0: tmp+=1
            if tmp>8: break
        if tmp==8: ans+=1
    
print(ans)