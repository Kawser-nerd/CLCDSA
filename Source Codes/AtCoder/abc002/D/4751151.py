#??

#define function
def fun1(x):
    for th in range(n):
        for item in x:
            d= True
            if alist[item][th]==0:
                d= False
                break
        if d:
            x.append(th)
    factionlist[x[0]]= x


#prepare alist
n, m= map(lambda x: int(x), input().split(' '))
alist= [[0 for i in range(n)] for i in range(n)]
for i in range(m):
    x, y= map(lambda x: int(x), input().split(' '))
    alist[x-1][y-1]= 1
    alist[y-1][x-1]= 1

#faction
factionlist= [[i] for i in range(n)]

for part_blist in factionlist:
    fun1(part_blist)
factionlist= list(map(lambda x: len(x), factionlist))
print(max(factionlist))