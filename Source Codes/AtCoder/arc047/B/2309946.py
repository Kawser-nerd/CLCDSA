u0 = v0 = 1e10; u1 = v1 = -1e10
N = int(input())
P = [list(map(int, input().split())) for i in range(N)]
for x, y in P:
    u0 = min(u0, x+y)
    u1 = max(u1, x+y)
    v0 = min(v0, x-y)
    v1 = max(v1, x-y)
du = u1 - u0
dv = v1 - v0

def check(u0, u1, v0, v1):
    if u1 - u0 != v1 - v0:
        return
    for x, y in P:
        if x+y in (u0, u1) and v0 <= x-y <= v1:
            continue
        if x-y in (v0, v1) and u0 <= x+y <= u1:
            continue
        return
    p = u0 + u1
    q = v0 + v1
    if (p + q) % 4 or (p - q) % 4:
        return
    x = (p + q) // 4
    y = (p - q) // 4
    print(x, y)
    exit(0)

check(u0, u1, v0, v1)
check(u0, u0+dv, v0, v1)
check(u1-dv, u1, v0, v1)
check(u0, u1, v0, v0+du)
check(u0, u1, v1-du, v1)
exit(1)