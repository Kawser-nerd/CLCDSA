N=int(input().strip())
a=[0]
b=list(map(int, input().split()))
for i in range(N):
    a.append(b[i])
a.append(0)

su=0
for i in range(N+1):
    su+=abs(a[i+1]-a[i])

for i in range(1,N+1):
    print(su-(abs(a[i+1]-a[i]))-abs(a[i]-a[i-1])+abs(a[i+1]-a[i-1]))