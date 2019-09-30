import sys

def m(tab, i):
    m = '9'
    for x in tab:
        if x > i:
            m = min(m, x)
    return m

def main():
    def next_line():
        return sys.stdin.readline()

    n = int(next_line())

    for nr in range(1,n+1):
        line = next_line()

        t = ['0'] + list(line)[:-1]

        rev = t[::-1]
        prev = rev[0]
        #print rev
        for pos, i in enumerate(rev[1:]):
            p = pos+2
            if prev > i:
                subtab = rev[:p]
                #print subtab
                x = m(subtab, i)
                subtab.remove(x)
                ret = sorted(subtab, reverse=True) + [x] + rev[p:]
                break
            prev = i

        ret = "".join( ret[::-1] )
        print "Case #%d: %d" % (nr, int(ret))

main()
