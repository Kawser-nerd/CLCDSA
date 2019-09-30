import itertools
l1 = list(map(int,input().split()))
l2 = itertools.combinations(l1,3)
l3 = []
for l in l2:
    l3.append(sum(l))
l3.sort()
print(l3[-3])