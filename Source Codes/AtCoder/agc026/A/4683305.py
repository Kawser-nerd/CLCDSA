N=int(input())
a=list(input().split())
ans=0
i=0
while i<(N-1):
    if a[i]==a[i+1]:
        ans+=1
        i+=2
    else:
        i+=1
print(ans)