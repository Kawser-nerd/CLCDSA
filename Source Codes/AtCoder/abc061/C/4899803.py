N, K = map(int, input().split())
L = sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: x[0])
num = 0
for a, b in L:
    num += b
    if K <= num:
        print(a)
        exit()