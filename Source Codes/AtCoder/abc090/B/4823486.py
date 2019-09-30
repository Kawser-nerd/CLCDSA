a,b=map(int,input().split())
ans=0
for i in range(a,b+1):
    tmp=str(i)
    if tmp[0]==tmp[-1] and tmp[1]==tmp[-2]:
        ans+=1
print(ans)