import collections

s = []
a = 0
x = input()
if len(x) % 2 != 0:
    print('No')
else:
    for i in x:
        s.append(i)
    c = collections.Counter(s)
    values, counts = zip(*c.most_common())
    for j in counts:
        if j % 2 == 0:
            a += 1
    if len(counts) == a:
        print('Yes')
    else:
        print('No')