f = open(0)
w = open(1, 'w')

H, W = map(int, f.readline().split())
INF = 10**18
P = []
A = B = 0
Am = Bm = INF
for s in f.readlines():
    lc = 0; rc = 0
    lp = -1; rp = -1

    mode = 0
    i = 0
    for c in s.strip():
        if c == 'o':
            if mode == 0:
                A += lc * (i - 1 - lp)
                lc += 1; lp = i
            else:
                if lc == 0:
                    Bm = min(Bm, rp)
                else:
                    if rp-lp > 2:
                        P.append((lc+rc, rp-lp-2, lc, rc))

                lc = 1; rc = 0
                lp = i; rp = -1
                mode = 0
        elif c == 'x':
            if mode == 0:
                rp = i
            B += (i - (rp+rc))
            mode = 1
            rc += 1
        i += 1
    if mode == 0:
        if lc:
            Am = min(Am, (W-1) - lp)
    else:
        if lc == 0:
            Bm = min(Bm, rp)
        else:
            if rp-lp > 2:
                P.append((lc+rc, rp-lp-2, lc, rc))

P.sort(reverse=1)
if Am < INF or Bm < INF:
    w.write("o\n" if Am <= Bm else "x\n")
    exit(0)

t = 0
for c, r, a, b in P:
    if t == 0:
        A += (r+1)//2 * (a-1)
        B += r//2 * (b-1)
    else:
        A += r//2 * (a-1)
        B += (r+1)//2 * (b-1)
    t ^= (r & 1)
if t == 0:
    w.write("o\n" if A > B else "x\n")
else:
    w.write("x\n" if A < B else "o\n")