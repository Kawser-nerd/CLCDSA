n,d,k = (int(i) for i in input().split())
lr = [[int(i) for i in input().split()] for i in range(d)]
st = [[int(i) for i in input().split()] for i in range(k)]

for s, t in st:
    nl = s
    nr = s
    cnt = 1
    for l, r in lr:
        if nl <= r and l <= nr:
            nl = min(nl,l)
            nr = max(nr, r)

            if nl <= t and t <= nr:
                print(cnt)
                break
        cnt+=1