n=int(input())
l=[int(input()) for i in range(n)]
a=1
ans=0
while a!=2:
    a=l[a-1]
    ans+=1
    if ans==n+1:
        ans=-1
        break
print(ans)