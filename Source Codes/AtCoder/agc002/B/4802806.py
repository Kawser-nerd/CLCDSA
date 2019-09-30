n,m=map(int,input().split())
boxs=[1]*n
TF=[1]+[0]*(n-1)
for i in range(m):
    a,b=map(int,input().split())
    if boxs[a-1]==0:
        continue
    else:
        boxs[a-1]-=1
        boxs[b-1]+=1
    if TF[a-1]==1 and boxs[a-1]==0:
        TF[a-1]=0
        TF[b-1]=1
    elif TF[a-1]==1:
        TF[b-1]=1
#print(boxs)
print(sum(TF))