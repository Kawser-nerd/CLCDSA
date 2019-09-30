from collections import defaultdict
d = defaultdict

n, c = map(int, input().split())
do = d(int)
de = d(int)
do[0] = 0
de[0] = 0
for i in range(n//2):   
    do[input()] += 1
    de[input()] += 1
if n%2:
    do[input()] += 1
o = max(do, key=do.get)
e = max(de, key=de.get)
if o != e:
    print((n-do[o]-de[e])*c)
else:
    vo = do.pop(o)
    ve = de.pop(e)
    vo2 = max(do.values())
    ve2 = max(de.values())
    print((n - max(vo+ve2, ve+vo2))*c)