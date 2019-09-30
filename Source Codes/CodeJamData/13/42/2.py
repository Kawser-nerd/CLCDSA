
def read() :
    return list(map(int, input().split(' ')))

def best(rank, tot) :
    if rank == tot - 1 :
        return 0
    return tot // 2 + best((rank + 1) // 2, tot // 2)

def worst(rank, tot) :
    if rank == 0 :
        return 0
    return tot // 2 + worst((rank - 1) // 2, tot // 2)

# print(worst(2, 8))

[T] = read()
for i in range(1, T + 1) :
    n, P = read()

    ans1, ans2 = 0, 2**n - 1

    L, R = 0, 2**n - 1
    while L < R :
        m = (L + R + 1) // 2
        if worst(m, 2**n) >= P :
            R = m - 1
        else :
            L = m
    ans1 = L

    L, R = 0, 2**n - 1
    while L < R :
        m = (L + R + 1) // 2
        if best(m, 2**n) < 2**n - P :
            R = m - 1
        else :
            L = m
    ans2 = L
    
    print('Case #%d: %d %d' % (i, ans1, ans2))
