n=int(input())
a=[int(input())for i in range(n)]
a.sort()
memo=a[0]
ans=0
cnt=0
for i in range(n):
    if a[i]==memo:
        cnt+=1
        if i==n-1:
            if cnt%2!=0:
                ans+=1
    else:
        if cnt%2!=0:
            ans+=1
        if i==n-1:
            ans+=1
        cnt=1

    memo=a[i]
print(ans)