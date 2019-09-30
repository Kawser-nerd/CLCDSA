import itertools
n = int(input())
h_list = []
for i in range(n):
    h_list.append(input()[0])
MARCH = ['M', 'A', 'R', 'C', 'H']
b = []
for a in MARCH:
    b.append(h_list.count(a))
bc = itertools.combinations(b, 3)
count = 0
for v in bc:
    count += v[0] * v[1] * v[2]
print(count)