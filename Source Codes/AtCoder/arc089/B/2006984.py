from itertools import accumulate

n, k = map(int, input().split())
k2 = k * 2
req_b = [[0] * k for _ in range(k)]
req_w = [[0] * k for _ in range(k)]
bc, wc = 0, 0
for i in range(n):
    x, y, c = input().split()
    x, y = int(x), int(y)
    rx, ry = x % k2, y % k2
    b = c == 'B'
    if rx >= k:
        rx -= k
        if ry >= k:
            ry -= k
        else:
            b = not b
    elif ry >= k:
        ry -= k
        b = not b
    if b:
        req_b[rx][ry] += 1
        bc += 1
    else:
        req_w[rx][ry] += 1
        wc += 1

req_b = [list(accumulate(req)) for req in req_b]
req_w = [list(accumulate(req)) for req in req_w]
req_b = [list(accumulate(req)) for req in zip(*req_b)]
req_w = [list(accumulate(req)) for req in zip(*req_w)]

ans = 0
kb, kw = req_b[-1], req_w[-1]
for dx, (dx_b, dx_w) in enumerate(zip(req_b, req_w)):
    dxk_b = dx_b[-1]
    dxk_w = dx_w[-1]
    for b1, w1, kyb, kyw in zip(dx_b, dx_w, kb, kw):
        b = bc - kyb - dxk_b + b1 * 2
        w = wc - kyw - dxk_w + w1 * 2
        a = b + wc - w
        ans = max(ans, a, n - a)
print(ans)