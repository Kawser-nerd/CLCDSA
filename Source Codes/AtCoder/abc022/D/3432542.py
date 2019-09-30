def d_bigbang(N, A, B):  # ????1??/2???????
    def dist2(x1, y1, x2, y2):
        return (x2 - x1)**2 + (y2 - y1)**2

    gx_a = gy_a = gx_b = gy_b = 0  # 1??/2????????????x/y??
    for x, y in A:
        gx_a += x
        gy_a += y
    for x, y in B:
        gx_b += x
        gy_b += y
    gx_a /= N
    gy_a /= N
    gx_b /= N
    gy_b /= N

    dist_a = dist_b = 0  # 1??/2????????????????????(?2?)
    for x, y in A:
        dist_a = max(dist_a, dist2(gx_a, gy_a, x, y))
    for x, y in B:
        dist_b = max(dist_b, dist2(gx_b, gy_b, x, y))
    # ???(???2???????????????)
    ans = '{0:.10f}'.format((dist_b / dist_a)**0.5)
    return ans
  
N = int(input())
A = [[int(i) for i in input().split()] for j in range(N)]
B = [[int(i) for i in input().split()] for j in range(N)]
print(d_bigbang(N, A, B))