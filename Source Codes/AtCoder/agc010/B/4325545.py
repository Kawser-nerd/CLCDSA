n = int(input())
a = [int(m) for m in input().split()]
p = []
for i in range(n):
    if i == n - 1:
        p.append(a[0] - a[n - 1])
    else:
        p.append(a[i + 1] - a[i])

k = sum(a) / ((n * (n + 1)) // 2)
if int(k) != k:
    print("NO")
    exit()
m = []
for i in range(n):
    mi = (k - p[i]) / n
    if int(mi) != mi or mi < 0:
        print("NO")
        exit()
    else:
        m.append(mi)

if sum(m) == k:
    print("YES")
else:
    print("NO")