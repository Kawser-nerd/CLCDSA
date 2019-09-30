from itertools import product

K, N = map(int, input().split())
items = []
for i in range(N):
    v, w = input().split()
    items.append((v, w))


def f(x):
    result = {}
    for v, w in items:
        cnt = 0
        for s in v:
            i = int(s)
            if i in result and result[i] != w[cnt:cnt + pattern[i - 1]]:
                return
            result[i] = w[cnt:cnt + pattern[i - 1]]
            cnt += pattern[i - 1]

        if cnt != len(w):
            return
    re = sorted(result.items(), key=lambda x: x[0])
    for k, v in re:
        print(v)
    exit()


for pattern in product(range(1, 4), repeat=K):
    f(pattern)