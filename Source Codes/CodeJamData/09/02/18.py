from sys import stdin
from sys import stdout

# N W E S
dr = [-1, 0, 0, 1]
dc = [0, -1, 1, 0]

T = int(stdin.readline().strip())

def color(r, c):
    global label, H, W, A, C
    if not C[r][c]:
        rn, cn = None, None
        for i in xrange(4):
            r2 = r + dr[i]
            c2 = c + dc[i]
            if 0 <= r2 < H and 0 <= c2 < W:
                if (A[r2][c2] < A[r][c]) and (rn is None or A[r2][c2] < A[rn][cn]):
                    rn, cn = r2, c2
        if rn is None:
            C[r][c] = chr(ord('a') + label)
            label += 1
        else:
            C[r][c] = color(rn, cn)
    return C[r][c]

for i in xrange(1, T + 1):
    line = stdin.readline()
    parts = line.split()
    H = int(parts[0])
    W = int(parts[1])
    A = []
    C = []
    for r in xrange(H):
        line = stdin.readline()
        parts = line.split()
        a = [int(s) for s in parts]
        A.append(a)
        C.append([None] * W)

    label = 0
    for r in xrange(H):
        for c in xrange(W):
            if not C[r][c]:
                color(r, c)

    stdout.write('Case #%d:\n' % i)
    for r in xrange(H):
        stdout.write('%s\n' % ' '.join(C[r]))
