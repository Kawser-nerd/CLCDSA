(n, m) = map(int, input().split())
lists = [int(input()) for _ in range(m)]
cases = [i for i in range(1, n + 1)]

cur = 0
for cd in lists:
    for i, j in enumerate(cases):
        if j == cd:
            tmp = cur
            cur = cases[i]
            cases[i] = tmp
            break

for cd in cases:
    print(cd)