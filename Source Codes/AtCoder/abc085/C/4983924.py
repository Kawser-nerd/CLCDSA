N, Y = map(int, input().split())
an_i = an_m = an_k = -1
for i in range(N + 1):
    for m in range(N - i + 1):
        k = N - i - m
        if (10000 * i + 5000 * m + 1000 * k) == Y:
            an_i, an_m, an_k = i, m, k
print(str(an_i) + ' ' + str(an_m) + ' ' + str(an_k))