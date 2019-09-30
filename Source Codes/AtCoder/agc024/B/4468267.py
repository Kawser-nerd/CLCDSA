n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

p = [0] * n

for i in range(n):
    if a[i] == 1:
        p[0] = 1
        continue
    if p[a[i] - 2] == 0:
        p[a[i] - 1] = 1
    else:
        p[a[i] - 1] = p[a[i] - 2] + 1
print(n - max(p))