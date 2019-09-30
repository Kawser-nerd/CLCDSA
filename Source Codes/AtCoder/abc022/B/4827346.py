import collections
n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
l = collections.Counter(a)
b = 0
for k in l.keys():
    if l[k] >= 2:
        b += l[k] - 1
print(b)