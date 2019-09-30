


def cal_layer(x,y):
    if x==0 and y==0:
        return 1

    if x==0:
        return (y/2)+1

    xx = x
    if xx < 0:
        xx -= y
        xx = -xx
    else:
        xx += y

    return (xx/2) + 1

def numlayer(l):
    return (l*2-1)*(l*2)/2

ctab = {}

def C(n,k):
    if (n,k) in ctab:
        return ctab[(n,k)]

    if k==0:
        return 1
    if n < k:
        ctab[(n,k)] = 0
        return 0

    c1 = C(n-1,k-1)
    c2 = C(n-1,k)
    val = c1 + c2
    ctab[(n,k)] = val
    return val

def solve():
    n,x,y = [int(x) for x in raw_input().split()]
    layer = cal_layer(x,y)

    if layer==1 and n > 0:
        return 1
    if n >= numlayer(layer):
        return 1
    if x==0 and n < numlayer(layer):
        return 0
    if n <= numlayer(layer-1):
        return 0

    m = n - numlayer(layer-1)
    k = y+1

    if m < k:
        return 0

    half = (layer - 1)*2
    
    if m-half >= k:
        return 1

    p = 0

    i = k
    while i <= m:
        x = C(i-1,i-k)*((0.5)**i)
        #print x
        p += x
        i += 1

    return p


def main():
    t = int(raw_input())
    for i in range(t):
        p = solve()
        print "Case #%d: %.7f" % (i+1,p)

#for i in range(1000):
#    print i+1,numlayer(i+1)

main()
