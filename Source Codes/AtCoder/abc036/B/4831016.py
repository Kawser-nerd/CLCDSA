N = int(input())
a = [[i for i in input()] for i in range(N)]
for i in range(N):
    s = ''
    for j in range(N):
        s += a[N - j - 1][i]
    print(s)