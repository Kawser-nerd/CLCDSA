n=int(input())
a=[list(map(int,input().split()))for i in range(n)]
h=0
for i in range(n-2):
    for j in range(i+1,n-1):
        for d in range(j+1,n):
            s=a[j][0]-a[i][0]
            t=a[d][0]-a[i][0]
            u=a[j][1]-a[i][1]
            r=a[d][1]-a[i][1]
            if abs(s*r-t*u)%2==0 and s*r!=t*u:
                h+=1
print(h)