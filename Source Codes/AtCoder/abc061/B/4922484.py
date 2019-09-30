n,m=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(m)]
city=[0 for i in range(n)]
for a,b in ab:
    city[a-1]+=1
    city[b-1]+=1
for i in city:
    print(i)