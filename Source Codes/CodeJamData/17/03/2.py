tnum = int(raw_input())

for ti in range(tnum):
    n, k = [int(x) for x in raw_input().split()[:2]]
    n += 1
    c = [1, 0]
    while c[0]+c[1]<k:
        k -= c[0]+c[1]
        d = [0, 0]
        cands = [(n//2, c[0]), ((n+1)//2, c[0]), ((n+1)//2, c[1]), ((n+2)//2, c[1])]
        for m, cnt in cands:
            if m==n//2:
                d[0] += cnt
            elif m==n//2+1:
                d[1] += cnt
            else:
                print 'What?'
        c = d
        n = n//2
    ans = n+1 if c[1]>=k else n
    print 'Case #{}: {} {}'.format(ti+1, (ans+1)//2-1, (ans)//2-1)
