N,K=map(int,input().split())

Base=0
Combo=0
ans=0

for i in range(N):
    num=int(input())
    if num>Base:
        Base=num
        Combo+=1
        if Combo>=K:
            ans+=1
            #print(i)
    else:
        Base=num
        Combo=1
        if Combo>=K:
            ans+=1

print(ans)