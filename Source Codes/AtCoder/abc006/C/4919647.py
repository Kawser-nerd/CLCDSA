n,m = map(int,input().split())

for a in range(n+1):
    for b in [0,1]:
        c = n-a-b
        if c >= 0:
            if a*2+b*3+c*4==m:
                print(a,b,c)
                exit()
print(-1,-1,-1)