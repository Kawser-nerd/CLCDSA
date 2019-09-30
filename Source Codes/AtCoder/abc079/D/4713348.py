h,w=map(int,input().split())
a=[list(map(int,input().split()))for i in range(10)]
b=[list(map(int,input().split()))for i in range(h)]
for h in range(10):
    for i in range(10):
        for j in range(10):
            if a[i][j]>a[i][h]+a[h][j]:
                a[i][j]=a[i][h]+a[h][j]
print(sum([sum([a[d][1] if d>=0 else 0 for d in i])for i in b]))