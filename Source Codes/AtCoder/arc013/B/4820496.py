c = int(input())
x = y = z = 0

for _ in range(c):
    L = list(map(int, input().split()))
    L.sort()
    x = max(x, L[0])
    y = max(y, L[1])
    z = max(z, L[2])

print(x*y*z)