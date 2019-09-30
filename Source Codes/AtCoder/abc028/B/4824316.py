import collections
s = list(input())
a = collections.Counter(s)
c = ["A", "B", "C", "D", "E", "F"]
d = []
for b in c:
    if b in a.keys():
        d.append(str(a[b]))
    else:
        d.append("0")
print(" ".join(d))