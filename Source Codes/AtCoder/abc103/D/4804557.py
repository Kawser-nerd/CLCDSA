from operator import itemgetter

N,M=map(int,input().split())
req=[list(map(int,input().split())) for i in range(M) ]

req.sort(key=itemgetter(1))

max=0
ans=0

for i in range(M):
    if not req[i][0]<=max<req[i][1]:
        max=req[i][1]-1
        ans+=1
        
print(ans)