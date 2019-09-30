import math

for tc in range(int(input())):
    Hd, Ad, Hk, Ak, B, D = map(int, input().split())
    Q = [(0, 'D', Hd, Ad, Hk, Ak)]
    r = None
    while Q:
        t, s, hd, ad, hk, ak = Q.pop(0)
        if 10000 < t:
            break
        if hk <= 0:
            r = t
            break
        if s in ['D']:
            if 0 < D and 0 < ak and hd > ak - D:
                Q.append((t + 1, 'D', hd - (ak - D), ad, hk, ak - D))
        if s in ['D', 'B']:
            if 0 < B and ad < hk and hd > ak:
                Q.append((t + 1, 'B', hd - ak, ad + B, hk, ak))
        if s in ['D', 'B', 'A']:
            if hd > ak or hk <= ad:
                Q.append((t + 1, 'A', hd - ak, ad, hk - ad, ak))
        if hd <= ak:
            Q.append((t + 1, s, Hd - ak, ad, hk, ak))
    if r is None:
        print("Case #{}: IMPOSSIBLE".format(tc + 1))
    else:
        print("Case #{}: {}".format(tc + 1, r))
