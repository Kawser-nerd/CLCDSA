N = int(input())
items = []
for _ in range(N):
    items.append(tuple(map(int, input().split())))


def check(x):
    f = True
    remain = [0] * N
    for i in range(N):
        h, s = items[i]
        remain[i] = (x - h) / s
    remain.sort()
    tmp = -1
    for r in remain:
        tmp += 1
        if tmp <= r:
            continue
        else:
            f = False
            break

    return f


ok = 10 ** 20
ng = 0
t = 0
while ok - ng > 1:
    mid = (ok + ng) // 2
    if check(mid):
        ok = mid
    else:
        ng = mid

print(ok)