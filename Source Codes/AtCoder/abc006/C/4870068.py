n,m=map(int,input().split())
if m<n*2 or n*4<m:
    print(-1,-1,-1)
else:
    if m>=n*3:
        z=m-n*3
        y=n-z
        x=0
    else:
        z=0
        y=m-n*2
        x=n-y
    print(x,y,z)