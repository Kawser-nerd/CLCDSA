D,G = map(int, input().split())
points = [0 for _ in range(D)]
for i in range(D):
    points[i] = list(map(int, input().split()))

def solve(d,g):
    if d <= 0:
        return 10**5
    n = min(g//(100*d), points[d-1][0])
    s = 100 * d * n
    if n == points[d-1][0]:
        s = d * points[d-1][0] * 100 + points[d-1][1]
    
    if g > s:
        n += solve(d-1, g-s)
    
    return min(n, solve(d-1, g))
print(solve(D,G))