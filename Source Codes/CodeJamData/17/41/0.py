from sys import stdin

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

(T,)=getInts()

for tc in xrange(1,1+T):
    (N,P)=getInts()
    Gs = getInts()
    Gs = [z % P for z in Gs]
    c = [len([z for z in Gs if z == i]) for i in xrange(P)]
    if P == 2:
        ans = c[0] + ((c[1] + 1)/2)
    elif P == 3:
        ans = 1 + c[0]
        k = min(c[1],c[2])
        ans += k
        c[1] -= k
        c[2] -= k
        ans += (c[1] / 3) + (c[2] / 3)
        if (c[1] + 2 * c[2]) % 3 == 0:
            ans -= 1
    elif P == 4:
        ans = 1 + c[0]
        # 1111
        # 3333
        # 22
        # 13
        # 112
        # 332
        # max a+b+c+d+e+f
        # given 4a+d+2e <= c[1]
        # 4b+d+2f <= c[3]
        # 2c+e+f <= c[2]
        rec = 0
        d = 0
        while d <= c[1] and d <= c[3]:
            e = 0
            while d + 2 * e <= c[1] and e <= c[2]:
                f = 0
                while d + 2 * f <= c[3] and e + f <= c[2]:
                    a = (c[1] - d - 2 * e) / 4
                    b = (c[3] - d - 2 * f) / 4
                    cv = (c[2] - e - f) / 2
                    score = a + b + cv + d + e + f
                    if score > rec:
                        rec = score
                    f += 1
                e += 1
            d += 1
        ans += rec
        if ((c[1] + 2 * c[2] + 3 * c[3]) % 4) == 0:
            ans -= 1
    print "Case #{}: {}".format(tc, ans)

        
