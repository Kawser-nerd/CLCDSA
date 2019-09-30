import bisect
def inpl(): return [int(i) for i in input().split()]

X = int(input())
K = int(input())
r = [0] + inpl()
stu = [()]*(K+1)
stu[0] = (X, 0, 0)
for i, v in enumerate(r[1:], 1):
    s, t, u = stu[i-1]
    if i%2:
        rs = r[i-1] - r[i]
        ap = - rs - t
        if ap >= s:
            stu[i] = 0, 0, 0
        elif ap >= u:
            stu[i] = s, t+rs, ap
        else:
            stu[i] = s, t+rs, u
    else:
        rs = r[i] - r[i-1]
        ap = X - rs - t
        if ap >= s:
            stu[i] = s, t+rs, u
        elif ap >= u:
            stu[i] = ap, t+rs, u
        else:
            stu[i] = X, 0, X
Q = int(input())
for _ in range(Q):
    ti, a = inpl()
    x = bisect.bisect_right(r, ti)
    ti -= r[x-1]
    s, t, u = stu[x-1]
    if a >= s:
        R = s + t
    elif a >= u:
        R = a + t
    else:
        R = u + t
    if x % 2:
        print(max(0, R - ti))
    else:
        print(min(X, R + ti))