K = int(input())
N = 50
a = [0] * 50

if K <= 50:
    for i in range(K):
        a[i] = 50
else:
    m = (K - 1) // 50
    base = 100 + m
    r = K % 50
    big = base - r
    small = big - 50 - r

    for i in range(r):
        a[i] = big
    for i in range(r, N, 1):
        a[i] = small

print(N)
print(" ".join(map(str, a)))