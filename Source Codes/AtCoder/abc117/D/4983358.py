def solve(n, k, a):
    x = [2**i for i in range(50, -1, -1)]
    ans = 0
    for x_i in x:
        u, v = 0, 0
        for a_j in a:
            u += x_i ^ (x_i & a_j)
            v +=       (x_i & a_j)
        if (x_i <= k) and (u > v):
            k -= x_i
            ans += u
        else:
            ans += v
    return ans

assert solve(3, 7, [1,6,3]) == 14
assert solve(4, 9, [7,4,0,3]) == 46

n, k = map(int, input().split())
a = list(map(int, input().split()))
print(solve(n, k, a))