N, M = list(map(int, input().split()))
X = sorted(list(map(int, input().split())))

if N >= M:
    print(0)
    exit()

path_cnt = sorted([X[i + 1] - X[i] for i in range(M - 1)])
if N == 1:
    print(sum(path_cnt))
else:
    print(sum(path_cnt[:-N + 1]))