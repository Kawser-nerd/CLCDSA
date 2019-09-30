X = int(input())
K = int(input())
rs = list(map(int,input().split()))
Q = int(input())
qs = [tuple(map(int,input().split())) for i in range(Q)]

dx = -1
ri = 0
offset = 0
upper,lower = X,0
prev_r = 0
ans = []
for t,a in qs:
    while ri < len(rs) and rs[ri] <= t:
        tmp_offset = dx * (rs[ri] - prev_r)
        if dx == 1:
            upper = min(X, upper + tmp_offset)
            lower = min(X, lower + tmp_offset)
        else:
            upper = max(0, upper + tmp_offset)
            lower = max(0, lower + tmp_offset)
        offset += tmp_offset
        dx *= -1
        prev_r = rs[ri]
        ri += 1
    a = max(lower, min(upper, a+offset))
    dt = t - prev_r
    a = max(0, min(X, a + dx*dt))
    ans.append(a)

print(*ans, sep='\n')