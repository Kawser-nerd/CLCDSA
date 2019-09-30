import sys
import math

PRIME_LIST = [2,3,5]

def gen_prime(upper_bound=2**16) :
    for i in range(max(PRIME_LIST)+1, upper_bound+1) :
        if find_divisor(i) is None :
            PRIME_LIST.append(i)
            
def is_prime(i) :
    if i <= PRIME_LIST[-1] :
        if (i in PRIME_LIST) :
            return True, None
        return False, find_divisor(i)
    d = find_divisor(i)
    return (d is None), d

def find_divisor(i) :
    isqrt = int(i**0.5)+1
    for p in PRIME_LIST :
        if i%p == 0 :
            return p
        if p > isqrt :
            break
    return None

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    N = int(argv[0])
    gen_prime()
    return ("%d primes generated under %d"%(len(PRIME_LIST), N))

def once():
    '''to cope once'''
    [N,J] = [int(x) for x in input().split()]
    LIM = 2**(N-2)
    s_mode = ("1%%%ds1"%(N-2))
    printerr(s_mode)
    n_found = 0
    d_ans = dict()
    for n in range(LIM) :
        s_b = (s_mode%(bin(n)[2:])).replace(" ","0")
        b_succ = True
        l = list()
        for base in range(2,11) :
            m = int(s_b, base)
            b_p, divisor = is_prime(m)
            if b_p :
                b_succ = False
                break
            l.append(divisor)
        if b_succ :
            d_ans[s_b] = l
            n_found += 1
            if n_found >= J :
                break
    return d_ans

def show(ans) :
    return '\n' + (
    '\n'.join(s + " " + " ".join(str(i) for i in l)
        for s,l in ans.items()))
    
def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, show(ans)))

if __name__ == '__main__' :
    msg = prework([16])
    print("prework done with", msg, file=sys.stderr)
    main()
