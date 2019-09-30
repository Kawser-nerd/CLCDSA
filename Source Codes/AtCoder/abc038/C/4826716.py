n=int(input())
X=list(map(int,input().split()))
cnt=1
ans=n
for i in range(n-1):
    if X[i]<X[i+1]:
        cnt+=1
        if i==n-2:
            ans+=(cnt-1)*cnt//2
    else:
        ans+=(cnt-1)*cnt//2
        cnt=1
print(ans)