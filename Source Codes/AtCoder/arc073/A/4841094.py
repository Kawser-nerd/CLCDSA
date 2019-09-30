N,T = map(int,input().split())
Ts = list(map(int,input().split()))
ans = T
for i in range(1,len(Ts)):
    middle= Ts[i]-Ts[i-1]
    if middle>T:
        ans+=T
    else:
        ans+=middle
print(ans)