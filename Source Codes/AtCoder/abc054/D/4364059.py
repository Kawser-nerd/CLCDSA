n, ma, mb = list(map(int, input().split()))
negs, poss, ans = [], [], 100 * n + 1
for _ in range(n):
    a, b, c = list(map(int, input().split()))
    sub = a * mb - b * ma
    if sub > 0:
        poss.append((sub, c))
    elif sub < 0:
        negs.append((-sub, c))
    else:
        ans = min(c, ans)

def sums(tups):
    ret = {0: 0}
    for x, c in tups:
        tmp = ret.copy()
        for x0, c0 in tmp.items():
            if x + x0 in ret:
                ret[x + x0] = min(c + c0, ret[x + x0])
            else:
                ret[x + x0] = c + c0
    del ret[0]
    return ret

nsum = sums(negs)
psum = sums(poss)

for v in nsum:
    if v in psum:
        ans = min(ans, nsum[v] + psum[v])
if ans == 100 * n + 1:
    ans = -1
print(ans)