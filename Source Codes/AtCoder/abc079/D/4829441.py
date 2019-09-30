H,W = list(map(int,input().split()))

c=[]
for i in range(10):
    c.append(list(map(int,input().split())))
A=[]
for i in range(H):
    A.append(list(map(int,input().split())))


for i in range(10):
    for j in range(10):
        for k in range(10):
            c[j][k] = min(c[j][k], c[j][i]+c[i][k])
res=0
for i in range(H):
    for j in range(W):
        if(A[i][j]>=0):
            res+=c[A[i][j]][1]
print(res)