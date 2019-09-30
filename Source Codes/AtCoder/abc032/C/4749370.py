n,k=[int(i) for i in input().split()]
s=[int(input()) for i in range(n)]
ans=0
if 0 in s:
    print(n)
else:
    left=0
    pod=1
    for i in range(left,n):
        pod*=s[i]
        if pod<=k:
            ans=max(ans,i-left+1)
        else:
            pod//=s[left]
            left+=1
    print(ans)