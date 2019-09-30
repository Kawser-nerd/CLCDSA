N,M =[int(i)for i in input().split()]
li =[1<<i for i in range(N)]
for _ in range(M):
    x,y =[int(i)-1 for i in input().split()]
    li[x] = li[x] | (1<<y)


lisDP =[{}for _ in range(N)]
for i in range(N):
    ke = 1<<i
    lisDP[0][ke]=1


for i in range(N-1):
    for bik,biv in lisDP[i].items():
        for j in range(N):
            if bik & li[j] ==0:
                foo = bik | (1<<j)
                if foo in lisDP[i+1].keys():
                    lisDP[i+1][foo] += biv
                else:
                    lisDP[i+1][foo] = biv

allnum = (1<<N) -1
print(lisDP[N-1][allnum])