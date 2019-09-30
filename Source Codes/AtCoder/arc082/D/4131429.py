#!/usr/bin/env python3
import bisect

def main():
    X = int(input())
    K = int(input())
    r = list(map(int, input().split()))
    Q = int(input())
    q_list = []
    for i in range(Q):
        q_list.append(list(map(int, input().split())))

    r = [0] + r
    a = [0]
    upper_limit = [X]
    lower_limit = [0]

    x, ux, lx = 0, X, 0
    for i in range(1, K + 1):
        diff = r[i] - r[i - 1]
        if i % 2 == 1:
            x -= diff
            ux -= diff
            ux = max(ux, 0)
            lx -= diff
            lx = max(lx, 0)
        else:
            x += diff
            ux += diff
            ux = min(ux, X)
            lx += diff
            lx = min(lx, X)
        a.append(x)
        upper_limit.append(ux)
        lower_limit.append(lx)

    asc_i = [0]
    dsc_i = [1]
    x = 0
    for i in range(2, K + 1, 2):
        if x < a[i]:
            x = a[i]
            asc_i.append(i)
    x = a[1]
    for i in range(3, K + 1, 2):
        if a[i] < x:
            x = a[i]
            dsc_i.append(i)

    asc_a = [a[i] for i in asc_i]
    dsc_a = [-a[i] for i in dsc_i]


    for [t, a0] in q_list:
        ri = bisect.bisect_right(r, t) - 1

        ui = bisect.bisect_left(asc_a, X - a0)
        li = bisect.bisect_left(dsc_a, a0)

        ai, di = None, None
        if ui < len(asc_i):
            ai = asc_i[ui]
            if ri < ai:
                ai = None
        if li < len(dsc_i):
            di = dsc_i[li]
            if ri < di:
                di = None

        d = 0
        if (not ai is None) or (not di is None):
            if ai is None:
                d = -1
            elif di is None:
                d = 1
            else:
                d = 1 if ai < di else -1

        x = a0 + a[ri]
        if d == 1:
            x = upper_limit[ri]
        elif d == -1:
            x = lower_limit[ri]
        x += (t - r[ri]) * (-1 if ri % 2 == 0 else 1)
        x = min(max(x, 0), X)

        print(x)

if __name__ == '__main__':
    main()