N=int(input())

mp=[0 for i in range(N)]
for a in input().split():
    mp[int(a)]+=1

res=True
if N%2==1:
    for i in range(2,N,2):
        if mp[i]!=2:
            res=False
    if mp[0]!=1:
        res=False
else:
    for i in range(1,N,2):
        if mp[i]!=2:
            res=False
if res:
    print(pow(2,N//2,10**9+7))
else:
    print(0)