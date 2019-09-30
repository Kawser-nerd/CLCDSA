N=int(input())
Open=[list(map(int,input().split())) for i in range(N)]
Profit=[list(map(int,input().split())) for i in range(N)]
ans=-1*float('inf')
for x in range(1,2**10):
    check=bin(x)[2:]
    check='0'*(10-len(check))+check
    now=0
    for i in range(N):
        cnt=0
        for k in range(10):
            if int(check[k])*Open[i][k]==1:
                cnt+=1
        now+=Profit[i][cnt]
    ans=max(ans,now)
print(ans)