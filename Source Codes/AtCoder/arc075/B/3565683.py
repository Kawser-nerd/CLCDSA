def inpl(): return [int(i) for i in input().split()]

N,A,B = inpl()
C = A-B
h = [int(input()) for _ in range(N)]

lo = -(-sum(h)//((N-1)*B+A)) -1
hi = sum([-(-i//A) for i in h]) 
while hi - lo > 1:
    me = (hi+lo)//2
    hprime = [h[i]-me*B for i in range(N) if h[i]-me*B >0]    
    hans = 0
    for j in hprime:
            hans += -(-j//C)
    if hans <= me:
        hi = me
    else:
        lo = me
print(hi)