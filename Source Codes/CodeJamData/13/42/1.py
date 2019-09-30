
def get_guaranteed(N,P):
    assert P > 0
    if N==0: return 0
    total = 2**N
    if P == total: return total-1
    if 2*P <= total: return 0
    tmp = get_guaranteed(N-1,P-total//2)
    return 2*tmp+2

def get_possible(N,P):
    assert P > 0
    if N==0: return 0
    total = 2**N
    if P == total: return total-1
    if P == total//2: return total-2
    if 2*P <= total:
        # vyhry len v prvej polovici
        tmp = get_possible(N-1,P)
        return 2*tmp
    else:
        # staci byt v druhej polovici
        # tmp = get_possible(N-1,P-total//2)
        # return (total//2) + tmp
        return total-2
    
T = int(input())
for t in range(1,T+1):
    N, P = [ int(x) for x in input().split() ]
    print("Case #{}: {} {}".format(t,get_guaranteed(N,P),get_possible(N,P)))

