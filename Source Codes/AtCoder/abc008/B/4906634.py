import collections
n = int(input())
s = []
for _ in range(n):
    s.append(input())
l = collections.Counter(s)
a = [k for k, v in sorted(l.items(), key=lambda x: x[1])]
print(a[-1])