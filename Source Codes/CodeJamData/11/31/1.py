#!/usr/bin/python
#use globals



def solve():
    for i in range(r):
        for j in range(c):
            if m[i][j] == '#':
                if j + 1 >= c or m[i][j+1] != '#':
                    return 'Impossible'
                else:
                    m[i][j+1] = '\\'
                if i + 1 >= r or m[i+1][j] != '#':
                    return 'Impossible'
                else:
                    m[i+1][j] = '\\'
                if m[i+1][j+1] != '#':
                    return 'Impossible'
                else:
                    m[i+1][j+1] = '/'
                m[i][j] = '/'
    return 'good'

r = input()
for case in range(1,r+1):
    l = map(int,raw_input().split())
    r, c = tuple(l)
    m = []
    for _ in range(r):
        m.append(list(raw_input()))
    sol = solve()
    print "Case #%s:" % case 
    if sol == 'good':
        for i in range(r):
            print ''.join(m[i])
    else:
        print sol
