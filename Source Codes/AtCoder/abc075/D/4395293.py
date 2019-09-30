from itertools import product
from operator import itemgetter
N, K = map(int, input().split())
XY = []
X, Y = [], []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    XY.append([x, y])
X.sort()
Y.sort()
XY.sort(key=itemgetter(1))

ans = 10 ** 19
for l, r, t in product(X, X, Y):
    if l > r:
        continue
    cnt = -K
    for x, y in XY:
        if y < t:
            continue
        if l <= x <= r:
            cnt += 1
            if cnt >= 0:
                area = (r - l) * (y - t)
                if area < ans:
                    ans = area
                break

print(ans)