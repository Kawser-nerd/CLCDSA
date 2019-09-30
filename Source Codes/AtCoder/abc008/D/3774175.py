w, h = map(int, input().split())
n = int(input())
device = [list(map(int, input().split())) for i in range(n)]

d = {}
def f(i, j, k, l):
    if (i, j, k, l) in d:
        return d[(i, j, k, l)]
    v = 0
    for x, y in device:
        x -= 1
        y -= 1
        if i <= x <= k and j <= y <= l:
            v = max(v, (k - i + 1) + (l - j + 1) - 1 + f(i, j, x-1, y-1) + f(i, y+1, x-1, l) + f(x+1, j, k, y-1) + f(x+1, y+1, k, l))
    d[(i, j, k, l)] = v
    return v

print(f(0, 0, w-1, h-1))