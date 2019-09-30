N = int(input())
d = {}
a = []
for i in range(N):
    temp = int(input())
    if temp not in d:
        d[temp] = 1
    a.append(temp)

d = sorted(list(d.keys()))
table = {}
for i, val in enumerate(d):
    table[val] = i

for val in a:
    print(table[val])