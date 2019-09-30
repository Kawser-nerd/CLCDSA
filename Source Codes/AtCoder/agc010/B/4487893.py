n = int(input())
a = list(map(int, input().split()))
if sum(a) % ((1 + n) * n // 2):
    print("NO")
else:
    m = sum(a) // ((1 + n) * n // 2)
    d = [0] * n
    for i in range(n):
        d[i] = a[(i + 1) % n] - a[i] - m
    for i in d:
        if i % n or i > 0:
            print("NO")
            exit()
    if -sum(d) == n * m:
        print("YES")
    else:
        print("NO")