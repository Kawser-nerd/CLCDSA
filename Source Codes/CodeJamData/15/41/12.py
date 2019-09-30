#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    R, C = [int(i) for i in input().split()]
    level = []
    for i in range(R):
        level.append(input())
    ans = 0
    for i in range(R):
        for j in range(C):
            if level[i][j] != '.':
                r = {}
                r['^'] = all(level[x][j] == '.' for x in range(i))
                r['<'] = all(level[i][x] == '.' for x in range(j))
                r['>'] = all(level[i][x] == '.' for x in range(j+1, C))
                r['v'] = all(level[x][j] == '.' for x in range(i+1, R))
                if not r[level[i][j]]: continue
                if all(r.values()):
                    ans = 'IMPOSSIBLE'
                    break
                ans += 1
        if ans == 'IMPOSSIBLE': break
    print("Case #{}: {}".format(case, ans))

