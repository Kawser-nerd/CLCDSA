n=list(map(int, input().split()))
n.sort()
if (n[1]-n[0])%2==1:
    ans=1
else:
    ans=0
ans+=n[2]-(n[0]+n[1])//2
print(ans)