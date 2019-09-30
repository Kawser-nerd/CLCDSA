N, A, B = map(int, input().split())
h = [int(input()) for _ in range(N)]
def fight(k):
    c = k
    for i in h:
        hp = i - B * k
        if hp > 0:
            c -= -(-hp // (A - B))
        if c < 0:
            return False
    return True

lo = 0
hi = 10 ** 9
while hi - lo > 1:
    mid = (lo + hi) // 2
    if fight(mid):
        hi = mid
    else:
        lo = mid
print(hi)