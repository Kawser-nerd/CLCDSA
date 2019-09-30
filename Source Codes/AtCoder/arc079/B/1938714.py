k = int(input())
n = 50
m = k % n
q = k // n

a = [q + n - m - 1] * n
for i in range(m):
    a[n - 1 - i] += n+1

print(n)
print(*a)