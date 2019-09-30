n,c = list(map(int,input().split()))

xv = []
go = []
goback = []
back = []
backgo = []

max1 = 0
sumt = 0

for i in range(n):
    xv.append(list(map(int,input().split())))
    sumt += xv[i][1]
    max1 = max(max1,sumt - xv[i][0])
    go.append(max1)
    goback.append(sumt - 2*xv[i][0])

max1 = 0
sumt = 0

for i in range(n)[::-1]:
    sumt += xv[i][1]
    max1 = max(max1, sumt - (c - xv[i][0]))
    back.append(max1)
    backgo.append(sumt - 2 * (c - xv[i][0]))

res = 0

for i in range(n-1):
    res = max(res,backgo[i]+go[-2-i],goback[i]+back[-2-i])

res = max(res,go[-1],back[-1],0)

print(res)