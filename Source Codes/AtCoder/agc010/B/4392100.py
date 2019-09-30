n = int(input())
a = list(map(int, input().split()))

if sum(a) % (n * (n+1) // 2) != 0:
    print("NO")
    exit()

k = sum(a) // (n * (n+1) // 2)
b = [0] * n
for i in range(n-1):
    b[i] = a[i+1] - a[i]
b[n-1] = a[0] - a[n-1]

for i in range(n):
    b[i] -= k

count = 0
for nb in b:
    if (-nb % n) != 0 or nb > 0:
        print("NO")
        exit()
    count += -nb // n

if count == k:
    print("YES")
else:
    print("NO")