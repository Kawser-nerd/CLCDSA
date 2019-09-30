
def nnext(u):
    u = str(u)
    l = [int(c) for c in u]
    for i in range(1, len(l)):
        l[i] = max(l[i], l[i - 1])
    return int("".join(str(k) for k in l))

def search(n):
    if nnext(n) == n: return n
    lo = 1
    hi = n
    lo = 1
    while hi - lo > 1:
        mi = (lo + hi) // 2
        if nnext(mi) > n:
            hi = mi
        else:
            lo = mi
    assert (nnext(lo) < n and nnext(nnext(lo) + 1) > n)
    return nnext(lo)

t = int(input())
for tc in range(1, t + 1):
    print("Case #" + str(tc) + ": ", end = "")
    n = int(input())
    print(search(n))
