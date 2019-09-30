import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    l = range(1000)
    def test(func) :
        lg = list(l)
        func(lg)
        return check(lg)
    ans = [(test(good), test(bad)) for _ in range(20)]
    print(*ans, sep='\n', file=sys.stderr)
    return "above"

import random
def good(l) :
    n = len(l)
    for k in range(n) :
        p = random.randint(k, n-1)
        l[k], l[p] = l[p], l[k]
def bad(l) :
    n = len(l)
    for k in range(n) :
        p = random.randint(0, n-1)
        l[k], l[p] = l[p], l[k]
    
def check(l) :
    a = len([1 for i,x in enumerate(l) if i-x>0])
    b = len([1 for i,x in enumerate(l) if i-x<0])
    r = a/b
    return r > 0.94

def once():
    '''to cope once'''
    n = int(input())
    l = [int(x) for x in input().split()]
    
    return "GOOD" if check(l) else "BAD"
    
    pass

def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
