H,W=map(int,input().split())
a=[list(map(int,input().split())) for i in range(H)]
count=0
ans=[]
for i in range(W):
    if i%2==0:
        for j in range(H):
            if j!=H-1:
                if a[j][i]%2==1:
                    a[j][i]-=1
                    a[j+1][i]+=1
                    ans.append([j+1,i+1,j+2,i+1])
                    count+=1
            else:
                if a[j][i]%2==1and i!=W-1:
                    a[j][i]-=1
                    a[j][i+1]+=1
                    ans.append([j+1,i+1,j+1,i+2])
                    count+=1
    if i%2==1:
        for j in reversed(range(H)):
            if j!=0:
                if a[j][i]%2==1:
                    a[j][i]-=1
                    a[j-1][i]+=1
                    ans.append([j+1,i+1,j,i+1])
                    count+=1
            else:
                if a[j][i]%2==1and i!=W-1:
                    a[j][i]-=1
                    a[j][i+1]+=1
                    ans.append([j+1,i+1,j+1,i+2])
                    count+=1
print(count)
for i in range(len(ans)):
    print(*ans[i])