from collections import Counter

n, m = map(int, input().split())
an = list(map(int, input().split()))
ac_ = Counter(an)
ac = {i: ac_[i] if i in ac_ else 0 for i in range(1, n + 1)}
ad = [0] * n
for a, c in ac.items():
    for i in range(max(0, a - c), a):
        ad[i] += 1
ans = ad.count(0)
anss = []

for x, y in (map(int, input().split()) for _ in range(m)):
    ax = an[x - 1]
    xdi = ax - ac[ax]
    if xdi >= 0:
        ad[xdi] -= 1
        if ad[xdi] == 0:
            ans += 1
    ac[ax] -= 1
    ac[y] += 1
    ydi = y - ac[y]
    if ydi >= 0:
        ad[ydi] += 1
        if ad[ydi] == 1:
            ans -= 1
    an[x - 1] = y
    anss.append(ans)
print('\n'.join(map(str, anss)))