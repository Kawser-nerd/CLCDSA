ai = lambda: list(map(int,input().split()))
ai_ = lambda: [int(x)-1 for x in input().split()]


s = input().split('T')
x,y = ai()

xx,yy = [],[]
c = 0
for i in range(len(s)):
    if i%2:
        yy.append(len(s[i]))
    else:
        xx.append(len(s[i]))

anx = set()
for i in range(len(xx)):
    if i == 0:
        anx = {xx[i]}
    else:
        aanx = set()
        for j in anx:
            aanx.add(j+xx[i])
            aanx.add(j-xx[i])
        anx = aanx
any = {0}
for i in range(len(yy)):
    aany = set()
    for j in any:
        aany.add(j+yy[i])
        aany.add(j-yy[i])
    any = aany

if x in anx and y in any:
    print('Yes')
else:
    print('No')