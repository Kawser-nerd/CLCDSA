from __future__ import division
import sys

def case():
    N = int(raw_input())
    matrix = [raw_input() for i in range(N)]
    gamess = []
    winss = []
    wps = []
    for i, row in enumerate(matrix):
        wins = games = 0
        for j, c in enumerate(row):
            if c != '.':
                games += 1
                if c == '1':
                    wins += 1
        gamess.append(games)
        winss.append(wins)
        wps.append(wins/games)
#        print >> sys.stderr, 'WP[%s] = %f' % (chr(i + 65), wps[-1])

    owps = []
    for i, row in enumerate(matrix):
        wptot = 0
        for j, c in enumerate(row):
            if c != '.':
                wptot += (winss[j] - (0 if c == '1' else 1))/(gamess[j] - 1)
        owps.append(wptot/gamess[i])
#        print >> sys.stderr, 'OWP[%s] = %f' % (chr(i + 65), owps[-1])

    rpis = []
    for i, row in enumerate(matrix):
        owptot = 0
        for j, c in enumerate(row):
            if c != '.':
                owptot += owps[j]
        oowp = owptot / gamess[i]
#        print >> sys.stderr, 'OOWP[%s] = %f' % (chr(i + 65), oowp)
#        print >> sys.stderr, '0.25*%f + 0.50*%f + 0.25*%f' % (wps[i], owps[i], oowp)
        rpis.append(0.25*wps[i] + 0.5*owps[i] + 0.25*oowp)

    return rpis

T = int(raw_input())
for i in xrange(1, T+1):
    print 'Case #%i:' % i
    print '\n'.join(('%0.12f' % ans) for ans in case())
