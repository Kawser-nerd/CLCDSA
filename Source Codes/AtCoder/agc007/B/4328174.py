n = int(input())
p = list(map(int, input().split()))

a = [0] * (n+1)
b = [0] * (n+1)

for i in range(n):
    if i == 0:
        continue
    a[p[i]-1] += i
    a[n] -= i
    b[0] += i
    b[p[i]] -= i

for i in range(n):
    a[i+1] += a[i]
    b[i+1] += b[i]

for i in range(n):
    ai = i+1
    bi = n-i
    a[i] += ai
    b[i] += bi

print(*a[:n])
print(*b[:n])