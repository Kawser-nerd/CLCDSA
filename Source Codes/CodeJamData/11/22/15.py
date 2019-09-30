#!/usr/bin/env python
# -*- coding: utf-8 -*-

def read(f):
    t = int(f.next())
    for i in xrange(t):
        vendors = []
        c, d = map(int, f.next().strip().split())
        for j in xrange(c):
            p, v = map(int, f.next().strip().split())
            vendors.append((p, v))
        yield vendors, d

def solve(vendors, distance):
    max_t = 0
    for i in xrange(len(vendors)):
        for j in xrange(i, len(vendors)):
            # print (vendors[i][0], vendors[j][0])
            n = 0
            for p, v in vendors[i:j+1]:
                n += v
            left = vendors[i][0]
            right = vendors[j][0]
            if n <= 1:
                continue
            t = float(distance * (n - 1) - (right - left)) / 2
            # print t, n
            if t > max_t:
                max_t = t
    return max_t

def main(f):
    for i, (vendors, distance) in enumerate(read(f)):
        # print vendors, distance
        t = solve(vendors, distance)
        print "Case #%d: %s" % (i+1, t)

_input = """
2
3 2
0 1
3 2
6 1
2 2
0 3
1 1
""".strip()

_output = """
Case #1: 1.0
Case #2: 2.5
""".strip()

def test_main(compare=False):
    import sys
    from difflib import unified_diff
    from StringIO import StringIO

    if compare:
        stdout = sys.stdout
        sys.stdout = StringIO()
        try:
            main(StringIO(_input))
            result = sys.stdout.getvalue().strip()
        finally:
            sys.stdout = stdout

        print result

        for line in unified_diff(result.splitlines(), _output.splitlines(),
                                 'Output', 'Expect', lineterm=''):
            print line

        if result == _output:
            print "OK"
        else:
            print "NG"

    else:
        main(StringIO(_input))

if __name__ == '__main__':
    test = False
    compare = True
    if test:
        test_main(compare)
    else:
        import sys
        if len(sys.argv) > 1:
            f = open(sys.argv[1])
            main(f)
            f.close()
        else:
            main(sys.stdin)
