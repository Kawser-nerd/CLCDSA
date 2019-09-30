def solve(dsize, fsizes):
    cnt = 0

    fsizes.sort(reverse=True)

    while True:
        s, k = None, None
        for i in range(len(fsizes)):
            if fsizes[i] != -1:
                s, k = fsizes[i], i
                break

        if not s:
            return cnt

        if k > 100:
            fsizes = fsizes[k:]
            k = 0

        fsizes[k] = -1
        cnt += 1

        d = None
        for i in range(len(fsizes)):
            if dsize - s >= fsizes[i] and fsizes[i] != -1:
                d = fsizes[i]
                j = i
                break

        if d and d != -1:
            fsizes[j] = -1
    return cnt


import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n, dsize = map(int, inf.readline().split())
            fsizes = map(int, inf.readline().split())
            outf.write('Case #{}: {}\n'.format(t,solve(dsize, fsizes)))