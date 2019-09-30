def memoize(f):
    d = {}
    def g(*args):
        if args not in d:
            d[args] = f(*args)
        return d[args]
    return g

def ints():
    return map(int,raw_input().split())

def debase(n,base):
    if n == 0:
        yield 0
    else:
        while n > 0:
            yield n % base
            n //= base

happies = set()
unhappies = set()
def happy(n,base):
    p = (n,base)
    if base == 2:
        return n != 0
    if n == 0:
        return False

    if p in happies:
        return True
    elif p in unhappies:
        return False

    seen = set()
    while n not in seen:
        seen.add(n)
        n = sum(x**2 for x in debase(n,base))
        if n == 1:
            happies.add(p)
            return True
    unhappies.add(p) # loop
    return False

def main():
    T,  = ints()

    for case in xrange(T):
        bases = ints()
        n = 1
        while True:
            n += 1
            if all(happy(n,base) for base in bases):
                print "Case #%s: %s" % ((case+1),n)
                break

if __name__ == '__main__':
    main()
