N,A,B = map(int,input().split())
H = [int(input()) for i in range(N)]
H.sort(reverse=True)

def defeat(k):
    n = 0
    for h in H:
        if h <= B*k: break
        h -= B*k
        n += -(-h//(A-B))
        if n > k:
            return False
    return True

ok = 10**18
ng = 0
while ok-ng > 1:
    m = (ok+ng)//2
    if defeat(m):
        ok = m
    else:
        ng = m
print(ok)