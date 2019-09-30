import itertools
K,N = map(int,input().split())
src = [input().split() for i in range(N)]

for ptn in itertools.product(range(1,4),repeat=K):
    d = [None] * K
    for v,w in src:
        i = 0
        for c in v:
            ci = int(c)-1
            if i + ptn[ci] > len(w): break
            if d[ci] is None:
                d[ci] = w[i:i+ptn[ci]]
            else:
                if d[ci] != w[i:i+ptn[ci]]: break
            i += ptn[ci]
        else:
            if i == len(w): continue
        break
    else:
        print(*d, sep='\n')
        exit()