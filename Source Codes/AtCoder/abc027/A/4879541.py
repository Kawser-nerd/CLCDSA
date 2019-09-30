import collections
l = [int(i) for i in input().split()]
a = collections.Counter(l)
b = len(set(l))
if b == 1:
    ans = l[0]
else:
    for k in a.keys():
        if a[k] == 1:
            ans = k
print(ans)