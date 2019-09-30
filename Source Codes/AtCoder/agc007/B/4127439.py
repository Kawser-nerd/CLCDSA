n = int(input())
p = [int(m) for m in input().split()]

a = [i * n + (i - 1) for i in range(1, n + 1)]
b = [i * n + (i - 1) for i in range(n, 0, -1)]

for i in range(n):
    a[p[i] - 1] += i + 1

for i in range(n):
    print(a[i],"", end="")
print()
for i in range(n):
    print(b[i],"", end="")