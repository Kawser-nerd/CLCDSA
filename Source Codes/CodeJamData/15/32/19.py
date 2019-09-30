def solve(K, L, S):
    for l in L:
        if K.count(l)==0:
            return 0.

    for i in range(1,len(L)+1):
        if L[i:]==L[:-i]:
            d = i
            break
    m = 1 + (S-len(L))/d

    p = 1.
    for l in L:
        p *= float(K.count(l))/len(K)

    return m - p*(S-len(L)+1)

for t in range(input()):
    _,_,S = map(int, raw_input().split())
    K = raw_input()
    L = raw_input()
    print "Case #%s: %.10f"%(t+1, solve(K,L,S))
