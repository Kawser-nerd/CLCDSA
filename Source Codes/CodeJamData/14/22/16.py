import sys

T = int(raw_input())

def to_binary(x):
        ret = []
        while x > 0:
                ret.append(x%2)
                x/=2
        if len(ret) == 0:
                return [0]
        return ret

def to_num(x):
        return sum([x[i] * (2**i) for i in xrange(len(x))]) + 1

rets = {}
def getans(a, b, k):
        assert(len(a) == len(b))
        assert(len(b) == len(k))
        if len(a) == 1:
                if k[0] == 0:
                        ans = 0
                else:
                        if a[0] == 0:
                                ans = b[0] + 1
                        else:
                                ans = b[0] + 2
                #print a, b, ans
                return ans
        if k[-1] == 0:
                if a[-1] == 1:
                        na = [1] * (len(a) - 1)
                else:
                        na = a[:-1]
                if b[-1] == 1:
                        nb = [1] * (len(b) - 1)
                else:
                        nb = b[:-1]
                if a[-1] == 0 and b[-1] == 0:                        
                        ans = getans(na, nb, k[:-1])
                elif a[-1] == 1 and b[-1] == 1:
                        ans = getans(na, nb, k[:-1]) #0 0
                        ans += getans(a[:-1], nb, k[:-1]) #1 0
                        ans += getans(na, b[:-1], k[:-1]) #0 1
                elif a[-1] == 1 and b[-1] == 0:
                        ans = getans(na, nb, k[:-1]) #0 0
                        ans += getans(a[:-1], nb, k[:-1]) #1 0
                elif a[-1] == 0 and b[-1] == 1:
                        ans = getans(na, nb, k[:-1]) #0 0
                        ans += getans(na, b[:-1], k[:-1]) #0 1
        else:
                assert(k[-1] == 1)
                one = 2**(len(a)-1)
                if a[-1] == 1 and b[-1] == 1:
                        ans = one * one # 0 0
                        ans += one * to_num(b[:-1])#0 1
                        ans += to_num(a[:-1]) * one # 1 0
                        ans += getans(a[:-1], b[:-1], k[:-1]) # 1 1
                elif a[-1] == 0 and b[-1] == 0:
                        ans = to_num(a[:-1]) * to_num(b[:-1])
                elif a[-1] == 1 and b[-1] == 0:
                        ans = one * to_num(b[:-1]) #0 0
                        ans += to_num(a[:-1]) * to_num(b[:-1]) #1 0
                else:
                        assert(a[-1] == 0 and b[-1] == 1)
                        ans = one * to_num(a[:-1]) #0 0
                        ans += to_num(a[:-1]) * to_num(b[:-1]) #0 1
        #print a, b, k, ans
        return ans




for i in xrange(T):
        sys.stdout.write('Case #%d: ' % (i+1))
        A, B, K = [int(x) for x in raw_input().split()]
        if K > A:
                K = A
        if K > B:
                K = B
        A -= 1
        B -= 1
        a = to_binary(A)
        b = to_binary(B)
        k = to_binary(K)
        maxlen = max(len(a), len(b), len(k))
        while len(a) < maxlen:
                a.append(0)
        while len(b) < maxlen:
                b.append(0)
        while len(k) < maxlen:
                k.append(0)

        #print a, b, k
        ans = getans(a, b, k)
        print ans

        
