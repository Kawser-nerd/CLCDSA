import sys
import os

f = open(sys.argv[1])

def fun(cs):
    dt = [ x.strip() for x in f.readline().split(" ") ]
    n = int(dt[0])
    m = int(dt[1])

    got = set('/')
    res = 0

    for i in range(n):
        line = f.readline().strip()
        ps = line.split("/")

        cur = ""
        for t in ps:
            cur = cur + "/" + t
            if cur not in got:
                got.add(cur)

    for i in range(m):
        line = f.readline().strip()
        ps = line.split("/")

        cur = ""
        for t in ps:
            cur = cur + "/" + t
            if cur not in got:
                got.add(cur)
                res += 1

    print "Case #%d: %d" % (cs, res)

def main():
    T = int(f.readline().strip())
    for i in range(T):
        fun(i+1)

main()
