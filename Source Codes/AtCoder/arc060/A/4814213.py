n, a = map(int, input().split())
x=list(map(lambda x: int(x)-a, input().split()))
k=[[0]*3000 for i in range(60)]
for i in range(3000):
    k[0][i]=0
k[0][x[0]+1500]+=1
k[0][1500]+=1
for i in range(1, n):
    for j in range(3000):
        if 3000>j-x[i]>=0:
            k[i][j]=k[i-1][j-x[i]]+k[i-1][j]
        else:
            k[i][j]=k[i-1][j]
print(k[n-1][1500]-1)