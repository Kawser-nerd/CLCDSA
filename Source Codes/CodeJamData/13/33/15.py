#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

""" END TEMPLATE JCHAOISAAC """

# global data



# global data

vowel = {
    'a': 1,
    'e': 1,
    'i': 1,
    'o': 1,
    'u': 1,
    }

def toMask(s):
    return map(lambda x: not  x in vowel, s)

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    attacks = []

    N = getint() # number of tribes
    for _ in xrange(N):
        d, n, w, e, s, dd, dp, ds = getints()
        for i in xrange(n):
            attacks.append(
                {
                    'd': d,
                    'w': w,
                    'e': e,
                    's': s,
                    }
                );
            d += dd
            w += dp
            e += dp
            s += ds

    attacks.sort(key=lambda x: x['d'])
    #print attacks

    # lame wall
    wall = {}
    for i in xrange(-1000 + 1, 1000):
        wall[i] = 0

    pd = 0
    upgrades = []
    for attack in attacks:
        
        d = attack['d']
        w = attack['w']
        e = attack['e']
        s = attack['s']

        # print d, w, e, s,  wall

        # upgrade complete!
        if d != pd:
            # print 'upgrade', upgrades
            for (ww, ee, ss) in upgrades:
                
                for p in xrange(ww * 2, ee * 2 + 1):
                    wall[p] = max(wall[p], ss)
            upgrades = []

        upgrades.append((w, e, s))


        win = False
        for p in xrange(w * 2, e * 2 + 1):
            if s > wall[p]:
                win = True
                break

        ans += 1 if win else 0

        pd = d


    # main
    print "Case #%d: %d" % (cases, ans) # answer output
