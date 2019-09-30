import sys
def readline():
    return sys.stdin.readline()
def c(n, k):
    if n < k:
        return 0
    r = 1
    k = min(k, n-k)
    for i in range(1, k+1):
        r = r * n / i
        n -= 1
    return r

def main():

    ncase = int(readline())
    for case in range(ncase):
        n, A, B, C, D, x0, y0, M = map(int, readline().split())
        ans = 0
        trees = []
        kind = {}
        x, y = x0, y0
        for i in range(n):
            trees.append((x, y))
            k = x%3, y%3
            if k not in kind:
                kind[k] = 0
            kind[k] += 1
            x = (A*x + B) % M
            y = (C*y + D) % M

        #for i1 in range(n):
        #    t1 = trees[i1]
        #    for i2 in range(i1+1, n):
        #        t2 = trees[i2]
        #        for i3 in range(i2+1, n):
        #            t3 = trees[i3]
        #            cx3 = t1[0] + t2[0] + t3[0]
        #            cy3 = t1[1] + t2[1] + t3[1]
        #            if cx3 % 3 == 0 and cy3 % 3 == 0:
        #                ans += 1

        #print kind

        for ki in range(len(kind)):
            for kj in range(ki, len(kind)):
                for kk in range(kj, len(kind)):
                    keys = kind.keys()
                    i = keys[ki]
                    j = keys[kj]
                    k = keys[kk]
                    cx3 = i[0] + j[0] + k[0]
                    cy3 = i[1] + j[1] + k[1]
                    if cx3 % 3 == 0 and cy3 % 3 == 0:
                        if i == j == k:
                            r = c(kind[i], 3)
                        elif i == j:
                            r = c(kind[i], 2) * kind[k]
                        elif j == k:
                            r = c(kind[j], 2) * kind[i]
                        elif i == k:
                            r = c(kind[i], 2) * kind[j]
                        else:
                            r = kind[i] * kind[j] * kind[k]
                        #print i, j, k, r
                        ans += r

                



            

        print 'Case #%d: %d' % (case+1, ans)

main()
