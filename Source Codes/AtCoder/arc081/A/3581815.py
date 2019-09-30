import collections
N = int(input())
A = list(map(int,input().split()))
c = collections.Counter(A)
c_l = c.most_common()
l = []
for e in c_l:
    if e[1] >= 4:
        l.append(e[0])
        l.append(e[0])
    elif e[1] >= 2:
        l.append(e[0])
l.sort()
if len(l) >= 2:
    print(l[-1]*l[-2])
else:
    print(0)