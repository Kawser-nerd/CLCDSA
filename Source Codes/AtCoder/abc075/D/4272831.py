n,k=map(int,input().split())
z=[list(map(int,input().split()))for _ in range(n)]
z.sort()
a=10**20
for i in range(n):
    for j in range(i+1,n):
        x=z[j][0]-z[i][0]
        l=sorted(t[1]for t in z[i:j+1])
        for u,v in zip(l,l[k-1:]):
            a=min(a,x*(v-u))
print(a)