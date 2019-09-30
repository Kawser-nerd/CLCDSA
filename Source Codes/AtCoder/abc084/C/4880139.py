from math import ceil
N = int(input())
CSF = [list(map(int, input().split())) for _ in range(N - 1)]

for j in range(N):
    if j == N - 1:
        print(0)
        exit()
    cc, ss, ff = CSF[j]
    t = ss + cc
    for i in range(j + 1, N - 1):
        c, s, f = CSF[i]
        if t <= s:
            t = s + c
        else:
            num = ceil(t / f)
            t = num * f + c
    print(t)