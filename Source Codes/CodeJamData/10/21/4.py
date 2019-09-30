#!/usr/bin/python


t = input()

for i in range(t):
    root = {}
    n, m = raw_input().strip('\n').split()
    n, m = int(n), int(m)

    for j in range(n):
        dirs = raw_input().strip('\n')[1:].split('/')
        now = root
        for d in dirs:
            now.setdefault(d, {})
            now = now[d]

    res = 0
    for j in range(m):
        dirs = raw_input().strip('\n')[1:].split('/')
        now = root
        for d in dirs:
            if d not in now:
                res += 1
                now[d] = {}
            now = now[d]
    print 'Case #' + str(i+1) + ': ' + str(res)

