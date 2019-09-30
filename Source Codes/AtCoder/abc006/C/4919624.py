n,m = map(int,input().split())
if 2*n==m:
    print(n,0,0)
    exit()
elif 3*n==m:
    print(0,n,0)
    exit()
for a in range(n):
    for b in [0,1]:
        c = n-a-b
        if c >= 0:
            if a*2+b*3+c*4==m:
                print(a,b,c)
                exit()
print(-1,-1,-1)