#!/usr/bin/python -SOO
for case in range(1,int(input())+1):
    h = [0]*500
    attacks = {}
    for _ in range(int(input())):
        d,n,w,e,s,dd,dp,ds = map(int,input().strip().split())
        for _ in range(n):
            if d not in attacks: attacks[d] = [(w,e,s)]
            else: attacks[d].append((w,e,s))
            d,w,e,s =  d+dd,w+dp,e+dp,s+ds
    ans = 0
    for d,l in sorted(attacks.items()):
        maxs = -1
        h2 = h[:]
        for w,e,s in l:
            maxs = max(maxs, s)
            success = 0
            for i in range(w+250,e+250):
                if h[i]<s: success = 1
                h2[i] = max(h2[i],s)
            ans += success
        h = h2
    print('Case #{}: {}'.format(case,ans))
