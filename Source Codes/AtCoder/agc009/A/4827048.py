n = int(input())
a = []
b = []
for _ in range(n):
    k, l = map(int, input().split())
    a.append(k)
    b.append(l)
s = 0
for i in range(n):
    j = n-1-i
    a[j] += s
    if a[j] % b[j] == 0:
        continue
    s += (a[j]//b[j] + 1) * b[j] - a[j]
print(s)