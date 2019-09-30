H,W=map(int,input().split())

a=[list(map(int,input().split())) for i in range(H)]
ans=[]
for i in range(H):
    for j in range(W-1):
        if a[i][j]%2==1:
            a[i][j+1]+=1
            ans.append(str(i+1)+" "+str(j+1)+" "+str(i+1)+" "+str(j+2))

for i in range(H-1):
    if a[i][W-1]%2==1:
        a[i+1][W-1]+=1
        ans.append(str(i+1)+" "+str(W)+" "+str(i+2)+" "+str(W))    



n=len(ans)
print(n)
for i in range(n):
    print(ans[i])