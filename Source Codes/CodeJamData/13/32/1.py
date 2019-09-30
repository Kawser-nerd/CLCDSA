#! /usr/bin/env python

T = int(input())
for TT in range(1, T + 1):
    x, y = [int(tmp) for tmp in input().split()]
    s = 0
    now = 1
    ans = ""
    while s < abs(x) +abs(y) or s % 2 != abs(x + y) % 2:
        s += now
        now += 1
    for i in range(now - 1, 0, -1):
        s -= i
        if abs(x - i) + abs(y) <= s:
            x -= i
            ans += 'E'
        elif abs(x + i) + abs(y) <= s:
            x += i
            ans += 'W'
        elif abs(x) + abs(y - i) <= s:
            y -= i
            ans += 'N'
        else:
            y += i
            ans += 'S'
    ans = ans[::-1]
    print("Case #" + str(TT) + ": " + ans)
