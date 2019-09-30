# seishin.py
N = int(input())
*P, = map(int, input().split())
M = [0]*(N+1)
for i, p in enumerate(P):
    M[p] = i

INF = 10**9
def init(P, n):
    n0 = 2 ** (n-1).bit_length()
    data = [INF]*(n0*2)
    data[n0-1:n0+n-1] = P
    for i in range(n0-2, -1, -1):
        data[i] = min(data[2*i+1], data[2*i+2])
    return data

def get_data(data, l, r):
    n0 = len(data)//2
    l += n0
    r += n0
    while l < r:
        if r&1:
            r -= 1
            yield data[r-1]
        if l&1:
            yield data[l-1]
            l += 1
        l >>= 1
        r >>= 1

def get(data, l, r):
    return min(get_data(data, l, r))

d0 = init(P[0::2], N//2)
d1 = init(P[1::2], N//2)

def query_x(l, r):
    if l % 2 == 0:
        x = get(d0, l//2, r//2)
    else:
        x = get(d1, l//2, r//2)
    return x
def query_y(l, r):
    if l % 2 == 0:
        y = get(d1, l//2, r//2)
    else:
        y = get(d0, (l+1)//2, (r+1)//2)
    return y

from heapq import heappush, heappop
que = [(query_x(0, N), 0, N)]
ans = []
while que:
    x, l, r = heappop(que)
    if l+2 < r:
        xi = M[x]
        y = query_y(xi, r)

        yi = M[y]

        # [l, xi)
        if l < xi:
            heappush(que, (query_x(l, xi), l, xi))
        # [xi+1, yi)
        if xi+1 < yi:
            heappush(que, (query_x(xi+1, yi), xi+1, yi))
        # [yi+1, r)
        if yi+1 < r:
            heappush(que, (query_x(yi+1, r), yi+1, r))
    else:
        y = P[r-1]

    ans.append("%d %d" % (x, y))
print(*ans)