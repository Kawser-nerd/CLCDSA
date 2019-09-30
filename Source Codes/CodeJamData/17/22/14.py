def solve(test):
    n, r, o, y, g, b, v = map(int, input().strip().split())

    if o == b and o > 0:
        if g != 0 or r != 0 or v != 0 or y != 0:
            print('IMPOSSIBLE')
        else:
            print('OB' * o)
        return

    if g == r and g > 0:
        if o != 0 or b != 0 or v != 0 or y != 0:
            print('IMPOSSIBLE')
        else:
            print('GR' * g)
        return

    if y == v and y > 0:
        if g != 0 or r != 0 or o != 0 or b != 0:
            print('IMPOSSIBLE')
        else:
            print('YV' * y)
        return

    if (o >= b and o > 0) or (g >= r and g > 0) or (v >= y and v > 0):
        print('IMPOSSIBLE')
        return
    b -= o
    r -= g
    y -= v

    a = [[b, 'B'], [r, 'R'], [y, 'Y']]
    a = sorted(a, reverse = True)
    if a[1][0] == 0: 
        print('IMPOSSIBLE')
        return
    ans = ''
    for i in range(a[0][0]):
        ans += a[0][1]
        if a[1][0] > 0:
            ans += a[1][1]
            a[1][0] -= 1
        elif a[2][0] > 0:
            ans += a[2][1]
            a[2][0] -= 1
        else:
            print('IMPOSSIBLE')
            return
    assert(a[1][0] == 0)
    for i in range(a[2][0]):
        pos = i * 2 + 1
        ans = ans[:pos] + a[2][1] + ans[pos:]
    for i in range(len(ans) - 1):
        assert(ans[i] != ans[i + 1])
    assert(ans[0] != ans[-1])

    vals = [o, g, v]
    lets = ['B', 'R', 'Y']
    subs = ['BOB', 'RGR', 'YVY']
    for k in range(3):
        for i in range(vals[k]):
            for j in range(len(ans)):
                if ans[j] == lets[k]:
                    ans = ans[:j] + subs[k] + ans[j + 1:]
                    break
    print(ans)

t = int(input())
for i in range(t):
    print('Case #%d: ' % (i + 1), end = "")
    solve(i)
