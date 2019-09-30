def bc(i):
    r = 0
    while i:
        if i & 1:
            r += 1
        i //= 2
    return r




T=int(input())
for t in range(T):
    N=int(input())
    W=[int(input(),2) for _ in range(N)]
    E=[set() for _ in range(N)]
    V={}
    Z=0
    for i in range(N):
        if W[i] == 0:
            Z+=1
            continue
        R = set()
        J = W[i]
        C = 1
        for v,k in V.items():
            if v & W[i]:
                J |= v
                C += k
                R.add(v)
        for r in R:
            del V[r]
        V[J] = C
    Req,Used=0,0
    O=[]
    for v,k in V.items():
        if k == bc(v):
            Req += k*k
            Used += k
        else:
            O.append((bc(v),k))
    if len(O) == 1:
        k=max(O[0])
        Req += k*k
        Used += k
    elif O:
        assert(len(O) == 2)
        k=max(O[0])
        l=max(O[1])
        if (k+l+Used <= N):
            Used += k+l
            Req += k*k+l*l
        else:
            k=max(O[0][0]+O[1][0],O[0][1]+O[1][1])
            Used += k
            Req += k*k

    K=sum((bc(w) for w in W))
    res=Req-K + N-Used
    print("Case #%d: %d" % (t+1, res))




