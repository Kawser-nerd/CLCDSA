a = [int(i) for i in input().split()]

l = []
for i in range(5):
    for j in range(i+1, 5):
        for k in range(j+1, 5):
            l.append(a[i]+a[j]+a[k])

print(sorted(l)[-3])