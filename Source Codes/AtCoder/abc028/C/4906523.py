a = list(map(int, input().split()))
l = []
for i in range(2 ** 5):
    if bin(i).count('1') != 3:
        continue
    tmp = 0
    for j in range(5):
        if ((i >> j) & 1) == 1:
            tmp += a[j]
    l.append(tmp)
l = list(set(l))
l.remove(max(l))
l.remove(max(l))
print(max(l))