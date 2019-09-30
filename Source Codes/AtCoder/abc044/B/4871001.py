w = input()

d = {}
for x in w:
    d[x] = d.get(x, 0) + 1

flag = True
for x in d.values():
    if x%2 != 0:
        flag = False

if flag:
    print('Yes')
else:
    print('No')