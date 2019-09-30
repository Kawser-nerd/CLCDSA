#!/usr/bin/env python
# -*- coding: utf-8 -*-

def read(f):
    t = int(f.next())
    for i in xrange(t):
        n = int(f.next())
        s = [f.next().strip() for j in xrange(n)]
        yield n, s

def calc_wp(s, p):
    win = total = 0
    for i, c in enumerate(s):
        if c == ".":
            continue
        if p is not None and i == p:
            # import pdb; pdb.set_trace()
            continue
        if c == "1":
            win += 1
        total += 1
    if total == 0:
        import pdb; pdb.set_trace()
    return float(win) / total

def average(it):
    seq = list(it)
    return float(sum(seq)) / len(seq)

def calc_owp(s, p):
    wp = {}
    for q in xrange(len(s)):
        wp[q] = calc_wp(s[q], p)
    def generator():
        for q in xrange(len(s)):
            if s[p][q] != ".":
                yield wp[q]
    return average(generator())

def calc_oowp(s, p, owp):
    # wp = {}
    # for q in xrange(len(s)):
    #     wp[q] = calc_wp(s[q], p)
    # owp = {}
    # for q in xrange(len(s)):
    #     owp[q] = calc_owp(s, q)
    def generator():
        for q in xrange(len(s)):
            if s[p][q] != ".":
                yield owp[q]
    return average(generator())

def main(f):
    wp = {}
    owp = {}
    oowp = {}
    for i, (n, s) in enumerate(read(f)):
        # print n, s
        for p in xrange(n):
            wp[p] = calc_wp(s[p], p)
        for p in xrange(n):
            owp[p] = calc_owp(s, p)
        for p in xrange(n):
            oowp[p] = calc_oowp(s, p, owp)
        print "Case #%d:" % (i + 1)
        for p in xrange(n):
            rpi = 0.25 * wp[p] + 0.50 * owp[p] + 0.25 * oowp[p]
            # print rpi, wp[p], owp[p], oowp[p]
            print rpi

_input = """
2
3
.10
0.1
10.
4
.11.
0.00
01.1
.10.
""".strip()

_output = """
Case #1:
0.5
0.5
0.5
Case #2:
0.645833333333
0.368055555556
0.604166666667
0.395833333333
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
