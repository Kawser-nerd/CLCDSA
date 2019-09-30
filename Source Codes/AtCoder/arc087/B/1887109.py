s = input()
x, y = map(int, input().split())

s2 = s.split('T')
dXs = list(map(len, s2[0::2]))
dYs = list(map(len, s2[1::2]))

memoX = {dXs[0]}
for i, dX in enumerate(dXs[1:]):
    memoX2 = set()
    for xNow in memoX:
        memoX2.add(xNow + dX)
        memoX2.add(xNow - dX)
    memoX = memoX2

memoY = {0}
for i, dY in enumerate(dYs):
    memoY2 = set()
    for yNow in memoY:
        memoY2.add(yNow + dY)
        memoY2.add(yNow - dY)
    memoY = memoY2

if x in memoX and y in memoY:
    print('Yes')
else:
    print('No')