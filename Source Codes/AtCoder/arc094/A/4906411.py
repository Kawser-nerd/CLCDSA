A, B, C = map(int, input().split())
M = max([A, B, C])


if (3*M) % 2 == (A+B+C) % 2:
    print((3 * M - A - B - C) // 2)
else:
    print((3 * (M+1) - A - B - C) // 2)