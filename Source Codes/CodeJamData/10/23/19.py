from math import factorial as fac
def comb(a, b) :
    if b==0 :
        return 1
    if b>a :
        return 0
    # return fac(a) / (fac(b) * fac(a-b))
    c = min(b, a-b) 
    s = 1
    for i in range(a, a-c, -1) :
        s *= i
    for i in range(2, c+1) :
        s /= i
    return s

a = {}
res = {}
MAX = 500
for n in range(2, MAX+1) :
    print n
    nres = 0
    a[n] = {}
    for k in range(1, n) :
        if k==1 :
            a[n][k] = 1
            nres += 1
            continue
        count = 0
        for p in range(1, k):
            count += a[k][p] * comb(n-k-1, k-p-1) 
        a[n][k] = count
        nres += count
    res[n] = nres
print res
def process_case() :
    n = int(raw_input())
    return "%d" % ( res[n] %100003 )

if __name__ == "__main__" :
    case_num = int(raw_input())
    for i in range(case_num) :
        result = process_case()
        print "Case #%d: %s" % (i+1, result)
