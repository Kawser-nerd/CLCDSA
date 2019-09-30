#!/usr/bin/env python3

score = { '.': 0, '+': 1, 'x': 1, 'o': 2 }

def row(r):
    return [(r, c) for c in range(n)]

def col(c):
    return [(r, c) for r in range(n)]

def drange(n):
    return range(-n+1, n)

def diag1(d): # '\'
    r = max(0, -d)
    c = max(0, d)
    return [(r+i, c+i) for i in range(n-abs(d))]

def diag2(d): # '/'
    return [(n-r-1, c) for (r, c) in diag1(d)]

def free(b, coords, val):
    return not any(b[r][c] in (val, 'o') for (r, c) in coords)

def dump(b):
    for row in b:
        print(' '.join(row))

def update(b, r, c, v):
    if b[r][c] == '.':
        b[r][c] = v
    elif b[r][c] in (v, 'o'):
        raise Exception("Can't update ({}, {}) to {} because it is {}".format(r, c, v, b[r][c]))
    else: # b[r][c] is the opposite of v
        b[r][c] = 'o'

def solve(b):
    free_rows = []
    for r in reversed(range(n)):
        if free(b, row(r), 'x'):
            free_rows.append(r)
    for c in range(n):
        if free(b, col(c), 'x'):
            r = free_rows.pop()
            update(b, r, c, 'x')
    if free_rows != []:
        raise Exception("Mismatched free rows and columns")
    free_diags = set([])
    for d in drange(n):
        if free(b, diag1(d), '+'):
            free_diags.add(d)
    for d in sorted(drange(n), key=abs, reverse=True):
        if free(b, diag2(d), '+'):
            for (r, c) in diag2(d):
                if c-r in free_diags:
                    free_diags.remove(c-r)
                    update(b, r, c, '+')
                    break
    return b

def build(p):
    b = [['.' for _ in range(n)] for _ in range(n)]
    for t, r, c in p:
        b[r][c] = t
    return b

def delta(b1, b2):
    n = len(b1)
    tot = 0
    out = []
    for i in range(n):
        for j in range(n):
            tot += score[b2[i][j]]
            if b1[i][j] != b2[i][j]:
                out.append((b2[i][j], i, j))
    return tot, out

def main():
    global n
    ts = int(input())
    for ti in range(ts):
        n, m = map(int, input().split(' '))
        lines = [input().split(' ') for _ in range(m)]
        p = [(t, int(r)-1, int(c)-1) for (t, r, c) in lines]
        b1 = build(p)
        b2 = [[v for v in r] for r in b1]
        #print("input:")
        #dump(b1)
        solve(b2)
        #print("output:")
        #dump(b2)
        tot, out = delta(b1, b2)
        print("Case #{}: {} {}".format(ti+1, tot, len(out)))
        for (t, r, c) in out:
            print(t, r+1, c+1)

if __name__ == '__main__':
    main()
