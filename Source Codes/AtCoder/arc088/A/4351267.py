X,Y=map(int,input().split())

ans=1
i=X
while(i*2<=Y):
        i*=2
        ans+=1
print(ans)