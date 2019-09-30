def s(n):
    if n < 10:
        return n
    else:
        return n % 10 + s(n // 10)
n = 0
for _ in range(int(input())):
    n += 1
    minn = n
    d = 1
    while n >= d:
        d *= 10
        m = (n // d + 1) * d - 1
        if minn * s(m) > m * s(minn):
            # minn / s(minn) > m / s(m)
            minn = m
    n = minn
    print(n)