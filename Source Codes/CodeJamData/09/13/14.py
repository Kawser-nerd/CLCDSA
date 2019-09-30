from __future__ import division

def memoize(f):
    d = {}
    def g(*args):
        if args not in d:
            d[args] = f(*args)
        return d[args]
    return g

def ints():
    return map(int,raw_input().split())

@memoize
def p(get,have,packsize,total):
    if get < 0:
        return 0
    elif get < packsize - have: # always get at least this many
        return 0
    elif get > total - have: # only this many to possibly get
        return 0
    elif packsize == 0:
        if get == 0:
            return 1
        else: # get > 0
            return 0
    else: # get >= 0, packsize > 0
        # draw duplicate \
        # draw new
        return have/total * p(get,have-1,packsize-1,total-1) \
            + (total - have)/total * p(get-1,have,packsize-1,total-1)

@memoize
def E(obtain,have,packsize,total):
    if obtain == have:
        return 0
    else:
        return (1 + sum(
            E(obtain,have+get,packsize,total) * p(get,have,packsize,total)
            for get in xrange(1, min(packsize,total-have)+1) # off by one, ahhhhhhhhhh
            )) / (1 - p(0,have,packsize,total))

def main():
    T,  = ints()

    for case in xrange(T):
        total,packsize = ints()
        print "Case #%s: %s" % ((case+1),E(total,0,packsize,total))

if __name__ == '__main__':
    main()
