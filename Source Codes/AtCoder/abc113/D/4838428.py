def way(h, w, k):
    if w == 1:
        return 1
    if [h, k] == [1, 1] or [h, k] == [1, 2]:
        return fibo[w - k]
    if h == 1:
        return 0
    if memo[h][k] != -1:
        return memo[h][k]
    re = way(h - 1, w, k) * fibo[k - 1] * fibo[w - k]
    if k != 1:
        re += way(h - 1, w, k - 1) * fibo[max(k - 2, 0)] * fibo[w - k]
    if k != w:
        re += way(h - 1, w, k + 1) * fibo[k - 1] * fibo[max(w - k - 1, 0)]
    memo[h][k] = re
    return re

h, w, k = map(int, input().split())
fibo = [1, 1]
for i in range(2, w):
    fibo += [fibo[i - 1] + fibo[i - 2]]
memo = [[-1] * (w + 1) for _ in range(h + 1)]

print(way(h, w, k) % 1000000007)