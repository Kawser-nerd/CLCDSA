def brute(P, A):
    from itertools import permutations
    best = 0
    for cand in permutations(A):
        bns = 0
        cur = 0
        for x in cand:
            if cur:
                cur += x
                cur %= P
            else:
                bns += 1
                cur += x
                cur %= P
        best = max(best, bns)
    return best

def solve(N, P, A):
    count = [0] * P
    for x in A:
        count[x%P] += 1
    if P == 2:
        return count[0] + count[1] / 2 + count[1] % 2
    if P == 3:
        c1, c2 = count[1], count[2]
        x=  min(c1,c2)
        ans = count[0] + x
        c1-=x
        c2 -= x
        ans += c1/3
        ans += c2/3
        c1 %=3
        c2 %=3
        if c1 or c2:
            ans += 1
        return ans
    if P == 4:
        #13 22 112 332 1111 3333
        ans = 0
        for a in xrange(N+1):
            for b in xrange(N+1):
                for c in xrange(N+1):
                    #suppose a 13s, b 112s, c 332s
                    
                    c1,c2,c3 = count[1],count[2],count[3]
                    c1 -= a+2*b
                    c2 -= b+c
                    c3 -= a+2*c

                    if c1<0 or c2<0 or c3<0: continue
                    bns = count[0] + a+b+c
                    #22 1111 3333
                    bns += c2 / 2
                    c2 %= 2
                    bns += c1 / 4
                    c1 %= 4
                    bns += c3 / 4
                    c3 %= 4
                    if c1 or c2 or c3:
                        bns += 1
                    ans =max(ans, bns)
        return ans

"""
A = [2, 3, 1, 1, 2, 1, 3]
print solve(len(A), 4, A)

if 1:
    from random import randint
    for _ in xrange(1000):
        print '.',
        N = randint(5, 8)
        A = [randint(1,3) for _ in xrange(N)]
        P = 4
        f1 = solve(N, P, A)
        f2 = brute(P, A)
        if f1 != f2:
            print 'err', f1, f2, A
"""
###
def main():
    with open('in.txt','r') as fi, \
            open('out.txt', 'w') as fo:
        rr = lambda: fi.readline().strip()
        rrM = lambda: map(int,rr().split())
        for tc in xrange(1, 1 + int(rr())):
            N, P = rrM()
            A = rrM()
            zeta = solve(N, P, A)
            outstr = "Case #%i: " % tc + str(zeta)
            print outstr
            fo.write(outstr+'\n')
            
if __name__ == "__main__": main()
