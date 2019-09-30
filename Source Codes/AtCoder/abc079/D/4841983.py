h, w = map(int, input().split())
c=[list(map(int, input().split())) for i in range(10)]
A=[list(map(int, input().split())) for i in range(h)]
for k in range(10):
    for i in range(10):
        for j in range(10):
            c[i][j]=min(c[i][j], c[i][k]+c[k][j])
cnt=[]      
for i in range(10):
    res=0
    for j in range(h):
        res+=A[j].count(i)
    cnt.append(res)    
print(sum(cnt[i]*c[i][1] for i in range(10)))