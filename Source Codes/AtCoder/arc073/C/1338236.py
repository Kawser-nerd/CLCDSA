n = int(input())
x = []
y = []
xy = []
maxlist = []
minlist = []
amax = 0
amin = 10**10
case1 = 0
case2 = 0
for i in range(n):
    store = [int(j) for j in input().split(' ')]
    if store[0] < store[1]:
        store[0], store[1] = store[1], store[0]
    if store[0] == amax:
        maxlist.append(i)
    elif store[0] > amax:
        amax = store[0]
        maxlist = [i]
    if store[1] == amin:
        minlist.append(i)
    elif store[1] < amin:
        amin = store[1]
        minlist = [i]
    x.append(store[0])
    y.append(store[1])
    xy.extend(store)

case1 = (max(x) - min(x)) * (max(y)-min(y))
for k in maxlist:
    if k in minlist:
        print(case1)
        exit()
for index in range(n):
    y[index] = [y[index], index]
y.sort()

bmax = y[n-1][0]
bmin = y[1][0]
xmin = 10**10
check = True
minsum = 10**10
for i in range(0, n-1):
    if x[y[i][1]] < xmin:
        xmin = x[y[i][1]]
    if x[y[i][1]] > bmax:
        bmax = x[y[i][1]]
    if check and xmin <= y[i+1][0]:
        bmin = xmin
        check = False
    elif check:
        bmin = y[i+1][0]
    if minsum > bmax - bmin:
        minsum = bmax - bmin
    if not check:
        break
case2 = minsum * (amax-amin)
print(min([case1, case2]))