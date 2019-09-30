
def comp(x, r):
    return 2 * x * x + (3 + 2 * r) * x + 2 * r + 1

def solve():
    
    R, T = map(int, input().split())

    l = 0
    r = T + 1
    while l + 1 < r:
        m = (l + r) // 2
        if comp(m - 1, R) <= T:
            l = m
        else:
            r = m

    return l    


T = int(input())
for tn in range(T):
    print("Case #{0}: {1}".format(tn + 1, solve()))

